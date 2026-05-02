import React, { useEffect, useRef, useState, forwardRef, useImperativeHandle } from 'react';
import * as THREE from 'three';
import { OrbitControls } from 'three/examples/jsm/controls/OrbitControls';
import { ViewportGizmo } from "three-viewport-gizmo";
import { TransformControls } from "three/examples/jsm/controls/TransformControls";
import URDFLoader from 'urdf-loader';
// All ROS communication is handled via the rosApi prop

const Viewer3D = forwardRef(({ previewJoints, showRealRobot = true, showGhostRobot = true, onGhostJointsChange, showFPS = true, showGhostRobotCoordinates = true, rosApi = null }, ref) => {
  const mountRef = useRef(null);
  const rendererRef = useRef(null);
  const cameraRef = useRef(null);
  const robotRef = useRef(null);
  const ghostRef = useRef(null);
  const sceneRef = useRef(null);
  const sphereRef = useRef(null);
  const translateCtrlRef = useRef(null);
  const rotateCtrlRef = useRef(null);
  const gizmoRef = useRef(null);
  const orbitRef = useRef(null);
  const gridRef = useRef(null);
  const hemiRef = useRef(null);
  // No direct ROS service/topic refs here; use rosApi
  const lastEmittedGhostJointsRef = useRef(null);
  const isDraggingTargetRef = useRef(false);
  const [fps, setFps] = useState(0);

  // No direct ROS context; rely on rosApi passed from parent

  const jointOrder = ['joint_1', 'joint_2', 'joint_3', 'joint_4', 'joint_5', 'gripperbase_to_armgearright'];

  const jointsEqual = (a, b) => {
    if (!a || !b) return false;
    for (const name of jointOrder) {
      const va = a[name];
      const vb = b[name];
      if (va === undefined && vb === undefined) continue;
      if (va === undefined || vb === undefined) return false;
      if (Math.abs(va - vb) > 1e-4) return false; // relaxed tolerance to reduce jitter
    }
    return true;
  };

  const emitGhostStateIfChanged = () => {
    if (!onGhostJointsChange) return;
    const current = collectGhostJoints();
    if (!jointsEqual(current, lastEmittedGhostJointsRef.current)) {
      lastEmittedGhostJointsRef.current = current;
      onGhostJointsChange(current);
      // Sync target sphere to current TCP if not being dragged
      if (!isDraggingTargetRef.current && sphereRef.current) {
        const ee = getEndEffector();
        if (ee) {
          ee.updateWorldMatrix(true, false);
          const p = new THREE.Vector3();
          const q = new THREE.Quaternion();
          ee.getWorldPosition(p);
          ee.getWorldQuaternion(q);
          sphereRef.current.position.copy(p);
          sphereRef.current.quaternion.copy(q);
          sphereRef.current.updateMatrixWorld(true);
        }
      }
    }
  };

  const setRobotJointValue = (robot, jn, val) => {
    if (robot && robot.joints && robot.joints[jn] !== undefined) {
      robot.setJointValue(jn, val);
      if (jn === 'gripperbase_to_armgearright' && robot.joints['gripperbase_to_armgearleft'] !== undefined) {
        robot.setJointValue('gripperbase_to_armgearleft', -val);
      }
    }
  };

  // Copy real robot joint angles into the ghost robot (make ghost take real pose)
  const copyRealToGhost = () => {
    if (!robotRef.current || !ghostRef.current) return;
    try {
      const rj = robotRef.current.joints || {};
      Object.keys(rj).forEach(jn => {
        const rv = rj[jn] && rj[jn].angle;
        if (rv !== undefined) {
          setRobotJointValue(ghostRef.current, jn, rv);
        }
      });
      // Notify parent about ghost change
      emitGhostStateIfChanged();
      // Snap sphere to new ghost EE
      const eeGhost = getEndEffector();
      if (eeGhost && sphereRef.current) {
        eeGhost.updateWorldMatrix(true, false);
        const npos = new THREE.Vector3();
        const nquat = new THREE.Quaternion();
        eeGhost.getWorldPosition(npos);
        eeGhost.getWorldQuaternion(nquat);
        sphereRef.current.position.copy(npos);
        sphereRef.current.quaternion.copy(nquat);
        sphereRef.current.updateMatrixWorld(true);
      }
    } catch (e) {
      // ignore
    }
  };

  const getEndEffector = () => {
    if (!ghostRef.current) return null;
    return ghostRef.current.getObjectByName('gripper_mid_point') || ghostRef.current.getObjectByName('base_gripper');
  };

  const collectGhostJoints = () => {
    const vals = {};
    if (ghostRef.current && ghostRef.current.joints) {
      Object.keys(ghostRef.current.joints).forEach(jn => {
        const j = ghostRef.current.joints[jn];
        if (j && j.angle !== undefined) vals[jn] = j.angle;
      });
    }
    return vals;
  };

  const lastValidPoseMmRef = useRef({ x: 0, y: 0, z: 0, qx: 0, qy: 0, qz: 0, qw: 1 });

  const lerpPose = (p1, p2, t) => ({
    x: p1.x + (p2.x - p1.x) * t,
    y: p1.y + (p2.y - p1.y) * t,
    z: p1.z + (p2.z - p1.z) * t,
    qx: p1.qx + (p2.qx - p1.qx) * t,
    qy: p1.qy + (p2.qy - p1.qy) * t,
    qz: p1.qz + (p2.qz - p1.qz) * t,
    qw: p1.qw + (p2.qw - p1.qw) * t,
  });

  const getEndEffectorPoseMeters = () => {
    const ee = getEndEffector();
    if (!ee) return null;
    ee.updateWorldMatrix(true, false);
    const p = new THREE.Vector3();
    const q = new THREE.Quaternion();
    ee.getWorldPosition(p);
    ee.getWorldQuaternion(q);
    return { x: p.x, y: p.y, z: p.z, qx: q.x, qy: q.y, qz: q.z, qw: q.w };
  };

  const computeIkAndApply = (poseMm, isRetry = false) => new Promise((resolve) => {
    const applySolved = (solved) => {
      Object.keys(solved).forEach(jn => {
        setRobotJointValue(ghostRef.current, jn, solved[jn]);
      });
      emitGhostStateIfChanged();
    };

    const seed = collectGhostJoints();
    
    if (rosApi && typeof rosApi.computeIK === 'function') {
      rosApi.computeIK(poseMm, seed).then(async (res) => {
        if (res?.ok && res.joints) {
          applySolved(res.joints);
          lastValidPoseMmRef.current = { ...poseMm };
          return resolve({ ok: true, joints: res.joints });
        }

        // If failed and not already a retry, try to find the "limit" via binary search
        if (!isRetry && lastValidPoseMmRef.current) {
          let low = 0.0; // last valid
          let high = 1.0; // unreachable target
          let bestRes = null;
          let bestPose = null;

          // 2 iterations of binary search is enough to feel like a "stretch" without too much spam
          for (let i = 0; i < 2; i++) {
            const mid = (low + high) / 2;
            const testPose = lerpPose(lastValidPoseMmRef.current, poseMm, mid);
            const r = await rosApi.computeIK(testPose, seed);
            if (r.ok) {
              low = mid;
              bestRes = r;
              bestPose = testPose;
            } else {
              high = mid;
            }
          }

          if (bestRes) {
            applySolved(bestRes.joints);
            lastValidPoseMmRef.current = { ...bestPose };
            return resolve({ ok: true, joints: bestRes.joints, stretched: true });
          }
        }

        return resolve({ ok: false, error: 'ik_unreachable' });
      });
      return;
    }
    resolve({ ok: false, error: 'ros_not_ready' });
  });

  // Imperative API
  useImperativeHandle(ref, () => ({
    getGhostState: () => {
      const joints = collectGhostJoints();
      const tcpM = getEndEffectorPoseMeters();
      let tcp = null;
      if (tcpM) tcp = { x: tcpM.x * 1000, y: tcpM.y * 1000, z: tcpM.z * 1000, qx: tcpM.qx, qy: tcpM.qy, qz: tcpM.qz, qw: tcpM.qw };
      return { joints, tcp };
    },
    // Compute TCP pose (in mm) for a given joints map by using the ghost model as a virtual FK solver
    getTCPFromJoints: (joints) => {
      if (!ghostRef.current) return null;
      // Save current ghost joints
      const prev = {};
      Object.keys(ghostRef.current.joints || {}).forEach(jn => { prev[jn] = ghostRef.current.joints[jn] && ghostRef.current.joints[jn].angle; });
      // Apply requested joints where available
      Object.keys(joints || {}).forEach(jn => {
        setRobotJointValue(ghostRef.current, jn, joints[jn]);
      });
      // Force update and read EE
      const eePose = getEndEffectorPoseMeters();
      // Restore previous joints
      Object.keys(prev).forEach(jn => {
        if (prev[jn] !== undefined) {
          setRobotJointValue(ghostRef.current, jn, prev[jn]);
        }
      });
      // Prevent emitting ghost change due to this temporary set by resetting lastSentJointsRef
      try { lastEmittedGhostJointsRef.current = collectGhostJoints(); } catch (e) { }
      if (!eePose) return null;
      return { x: eePose.x * 1000, y: eePose.y * 1000, z: eePose.z * 1000, qx: eePose.qx, qy: eePose.qy, qz: eePose.qz, qw: eePose.qw };
    },
    setGhostJoints: (joints) => {
      if (!ghostRef.current || !joints) return;
      Object.keys(joints).forEach(jn => {
        setRobotJointValue(ghostRef.current, jn, joints[jn]);
      });
      emitGhostStateIfChanged();
    },
    solveAndMoveToPose: (poseMm, opts = {}) => computeIkAndApply(poseMm, opts),
    publishGhostToController: () => {
      const current = collectGhostJoints();
      // Prefer centralized publisher when available
      if (rosApi && typeof rosApi.publishJointGroupCommand === 'function') {
        // Build a joints map with the expected sign for gripper
        const toSend = { ...current };
        // The gripper value is already computed correctly in the UI (FK/IK)
        if (toSend['gripperbase_to_armgearright'] !== undefined) {
          // just pass it as is
          toSend['gripperbase_to_armgearright'] = toSend['gripperbase_to_armgearright'];
        }
        rosApi.publishJointGroupCommand(jointOrder, toSend);
        return;
      }
      // No-op if API not available
    },
    snapTargetToTCP: () => {
      const ee = getEndEffector();
      if (!ee || !sphereRef.current) return;
      ee.updateWorldMatrix(true, false);
      const p = new THREE.Vector3();
      const q = new THREE.Quaternion();
      ee.getWorldPosition(p);
      ee.getWorldQuaternion(q);
      sphereRef.current.position.copy(p);
      sphereRef.current.quaternion.copy(q);
      sphereRef.current.updateMatrixWorld(true);
    },
    syncTargetToTCP: () => {
      const ee = getEndEffector();
      if (!ee || !sphereRef.current) return;
      ee.updateWorldMatrix(true, false);
      const p = new THREE.Vector3();
      const q = new THREE.Quaternion();
      ee.getWorldPosition(p);
      ee.getWorldQuaternion(q);
      sphereRef.current.position.copy(p);
      sphereRef.current.quaternion.copy(q);
      sphereRef.current.updateMatrixWorld(true);
    }
    ,
    // Force the renderer/camera to resize based on mount dimensions (useful when sidebar width changes)
    forceResize: () => {
      try {
        if (!mountRef.current || !rendererRef.current || !cameraRef.current) return;
        const width = mountRef.current.offsetWidth;
        const height = mountRef.current.offsetHeight;
        rendererRef.current.setSize(width, height);
        cameraRef.current.aspect = width / height;
        cameraRef.current.updateProjectionMatrix();
        if (gizmoRef.current && typeof gizmoRef.current.update === 'function') gizmoRef.current.update();
      } catch (e) {
        console.error('forceResize failed', e);
      }
    }
    ,
    // Toggle TransformControls space between local and world
    toggleTCPGizmoFrame: () => {
      const t = translateCtrlRef.current;
      const r = rotateCtrlRef.current;
      if (!t && !r) return;
      const newSpace = (t && t.space === 'local') || (r && r.space === 'local') ? 'world' : 'local';
      if (t) t.setSpace(newSpace);
      if (r) r.setSpace(newSpace);
    }
    ,
    // Allow external callers to copy the real robot pose into the ghost
    copyRealToGhost: () => copyRealToGhost(),
  }), [rosApi?.connected]);

  // Init scene
  useEffect(() => {
    if (!mountRef.current) return;

    const width = mountRef.current.offsetWidth;
    const height = mountRef.current.offsetHeight;

    const camera = new THREE.PerspectiveCamera(45, width / height, 0.1, 100);
    camera.up.set(0, 0, 1);
    camera.position.set(-1, 1, 1);
    cameraRef.current = camera;

    const scene = new THREE.Scene();
    scene.background = new THREE.Color(0x333333);
    sceneRef.current = scene;
    // Grid on Z=0 (XY plane) since this app uses Z as up
    const grid = new THREE.GridHelper(4, 40, 0x222222, 0x111111);
    // GridHelper is XZ by default; rotate to XY plane
    grid.rotation.x = Math.PI / 2;
    grid.position.set(0, 0, 0);
    if (grid.material) {
      grid.material.opacity = 0.5;
      grid.material.transparent = true;
    }
    scene.add(grid);
    gridRef.current = grid;

    const renderer = new THREE.WebGLRenderer({ antialias: true });
    renderer.setSize(width, height);
    renderer.setPixelRatio(window.devicePixelRatio);
    rendererRef.current = renderer;
    while (mountRef.current.firstChild) mountRef.current.removeChild(mountRef.current.firstChild);
    mountRef.current.appendChild(renderer.domElement);

    const light = new THREE.DirectionalLight(0xffffff, 0.6);
    light.position.set(-5, 10, 7.5);
    scene.add(light);
    const ambientLight = new THREE.AmbientLight(0x404040);
    scene.add(ambientLight);
    // Hemisphere light for soft sky/ground illumination
    const hemi = new THREE.HemisphereLight(0xffffbb, 0x080820, 0.2);
    hemi.position.set(0, 0, 10);
    scene.add(hemi);
    hemiRef.current = hemi;

    const orbit = new OrbitControls(camera, renderer.domElement);
    orbitRef.current = orbit;
    const gizmo = new ViewportGizmo(camera, renderer, { type: 'sphere' });
    gizmo.attachControls(orbit);
    gizmo.target.set(0, 0, 0.3);
    camera.lookAt(gizmo.target);
    gizmo.update();
    gizmoRef.current = gizmo;

    // Animation with an effective FPS limiter
    let lastTime = 0;
    const targetFPS = 30;
    const frameInterval = 1000 / targetFPS;
    let frameCount = 0;

    const logFPS = setInterval(() => { setFps(frameCount); frameCount = 0; }, 1000);

    const animate = (currentTime) => {
      if (currentTime - lastTime >= frameInterval) {
        frameCount++;
        requestAnimationFrame(animate);
        if (ghostRef.current) {
          emitGhostStateIfChanged();
          // Keep sphere following TCP when not dragging
          if (!isDraggingTargetRef.current && sphereRef.current) {
            const ee = getEndEffector();
            if (ee) {
              ee.updateWorldMatrix(true, false);
              const p = new THREE.Vector3();
              const q = new THREE.Quaternion();
              ee.getWorldPosition(p);
              ee.getWorldQuaternion(q);
              sphereRef.current.position.copy(p);
              sphereRef.current.quaternion.copy(q);
              sphereRef.current.updateMatrixWorld(true);
            }
          }
          ghostRef.current.traverse(obj => {
            if (obj.isMesh) {
              if (Array.isArray(obj.material)) {
                obj.material = obj.material.map(() => new THREE.MeshPhongMaterial({ color: 0x2196f3, opacity: 0.4, transparent: true, depthWrite: false }));
              } else {
                obj.material = new THREE.MeshPhongMaterial({ color: 0x2196f3, opacity: 0.4, transparent: true, depthWrite: false });
              }
              obj.material.needsUpdate = true;
              obj.material.vertexColors = false;
            }
          });
        }
        renderer.toneMapping = THREE.CineonToneMapping;
        renderer.render(scene, camera);
        renderer.toneMapping = THREE.NoToneMapping;
        gizmo.render();
        lastTime = currentTime;
      } else {
        requestAnimationFrame(animate);
      }
    };
    requestAnimationFrame(animate);

    renderer.setPixelRatio(Math.min(window.devicePixelRatio, 2));
    renderer.shadowMap.enabled = false;

    const handleResize = () => {
      if (mountRef.current && rendererRef.current) {
        const width = mountRef.current.offsetWidth;
        const height = mountRef.current.offsetHeight;
        rendererRef.current.setSize(width, height);
        camera.aspect = width / height;
        camera.updateProjectionMatrix();
        gizmo.update();
      }
    };
    window.addEventListener('resize', handleResize);

    return () => {
      window.removeEventListener('resize', handleResize);
      if (rendererRef.current) rendererRef.current.dispose();
      if (gridRef.current && sceneRef.current) sceneRef.current.remove(gridRef.current);
      if (hemiRef.current && sceneRef.current) sceneRef.current.remove(hemiRef.current);
      clearInterval(logFPS);
    };
  }, []);

  // Load URDF and subscribe to joint states via rosApi
  useEffect(() => {
    if (!rosApi || !rosApi.connected) return;
    if (!sceneRef.current || !cameraRef.current || !rendererRef.current) return;

    let unsubscribeJointStates = null;

    // Load URDF and add to scene
    const loadUrdf = (urdfXml) => {
      if (!urdfXml) return;
      const loader = new URDFLoader();
      loader.workingPath = '/gryphon_urdf';
      loader.fetchOptions = { mode: 'cors' };
      // Real robot
      const robot = loader.parse(urdfXml);
      robot.rotation.x = 0;
      robot.rotation.z = 0;
      robot.scale.set(1, 1, 1);
      sceneRef.current.add(robot);
      robotRef.current = robot;
      // Ghost robot
      const ghost = loader.parse(urdfXml);
      ghost.rotation.x = 0;
      ghost.rotation.z = 0;
      ghost.scale.set(1, 1, 1);
      sceneRef.current.add(ghost);
      ghostRef.current = ghost;

      // Sphere at TCP
      const eeLink = getEndEffector();
      if (eeLink) {
        eeLink.updateWorldMatrix(true, false);
        const pos = new THREE.Vector3();
        eeLink.getWorldPosition(pos);
        const sphere = new THREE.Mesh(new THREE.SphereGeometry(0.02, 32, 32), new THREE.MeshPhongMaterial({ color: 0x4caf50, opacity: 0.5, transparent: true }));
        sphere.position.copy(pos);
        sceneRef.current.add(sphere);
        sphereRef.current = sphere;

        // Dual TransformControls: translate (arrows) + rotate (rings) both visible
        const translateControl = new TransformControls(cameraRef.current, rendererRef.current.domElement);
        translateControl.attach(sphere);
        translateControl.setMode('translate');
        translateControl.setSpace('world');
        translateControl.setSize(1.0);
        sceneRef.current.add(translateControl.getHelper());
        translateCtrlRef.current = translateControl;

        const rotateControl = new TransformControls(cameraRef.current, rendererRef.current.domElement);
        rotateControl.attach(sphere);
        rotateControl.setMode('rotate');
        rotateControl.setSpace('world');
        rotateControl.setSize(0.85);
        sceneRef.current.add(rotateControl.getHelper());
        rotateCtrlRef.current = rotateControl;

        const orbit = orbitRef.current;
        const domEl = rendererRef.current.domElement;

        // Prevent OrbitControls from stealing pointer events.
        // Check BOTH controls' axis property in capture phase.
        domEl.addEventListener('pointerdown', () => {
          if (translateControl.axis || rotateControl.axis) {
            if (orbit) orbit.enabled = false;
          }
        }, { capture: true });

        domEl.addEventListener('pointerup', () => {
          if (orbit) orbit.enabled = true;
          isDraggingTargetRef.current = false;
        });

        translateControl.addEventListener('dragging-changed', (e) => {
          if (orbit) orbit.enabled = !e.value;
          if (rotateControl) rotateControl.enabled = !e.value;
          isDraggingTargetRef.current = e.value;
        });
        rotateControl.addEventListener('dragging-changed', (e) => {
          if (orbit) orbit.enabled = !e.value;
          if (translateControl) translateControl.enabled = !e.value;
          isDraggingTargetRef.current = e.value;
        });

        // IK visual feedback
        let lastValidPos = sphere.position.clone();
        let lastValidQuat = sphere.quaternion.clone();
        const reachableColor = new THREE.Color(0x4caf50);
        const unreachableColor = new THREE.Color(0xff4757);

        // Anti-spam: track consecutive failures and request sequencing
        let consecutiveFailures = 0;
        let lastSentPos = sphere.position.clone();
        let lastSentQuat = sphere.quaternion.clone();
        let ikRequestId = 0; // monotonically increasing ID to ignore stale responses
        const MAX_CONSECUTIVE_FAILURES = 3;
        const MIN_MOVE_TO_RETRY_MM = 5;      // must move >5mm to retry after backoff
        const MIN_ROTATE_TO_RETRY_RAD = 0.09; // ~5° to retry after backoff

        const sendIKFromSphere = () => {
          if (!sphereRef.current) return;
          // Throttle: 150ms between IK calls (was 50ms)
          if (sendIKFromSphere.__locked) return;
          sendIKFromSphere.__locked = true;
          setTimeout(() => { sendIKFromSphere.__locked = false; }, 150);

          sphereRef.current.updateMatrixWorld(true);
          const p = new THREE.Vector3();
          const q = new THREE.Quaternion();
          sphereRef.current.getWorldPosition(p);
          sphereRef.current.getWorldQuaternion(q);

          // Backoff: if too many consecutive failures, only retry when the
          // sphere has moved significantly from where the failures started
          if (consecutiveFailures >= MAX_CONSECUTIVE_FAILURES) {
            const posDeltaMm = p.clone().sub(lastSentPos).length() * 1000;
            const rotDeltaRad = lastSentQuat.angleTo(q);
            if (posDeltaMm < MIN_MOVE_TO_RETRY_MM && rotDeltaRad < MIN_ROTATE_TO_RETRY_RAD) {
              return; // skip — sphere hasn't moved enough to warrant another try
            }
            // Moved enough; reset backoff and let it try again
            consecutiveFailures = 0;
          }

          lastSentPos = p.clone();
          lastSentQuat = q.clone();
          const poseMm = { x: p.x * 1000, y: p.y * 1000, z: p.z * 1000, qx: q.x, qy: q.y, qz: q.z, qw: q.w };

          // Tag this request so we can ignore stale responses
          const thisRequestId = ++ikRequestId;

          computeIkAndApply(poseMm).then((res) => {
            // Ignore stale response — a newer request was already sent
            if (thisRequestId !== ikRequestId) return;
            if (!sphereRef.current) return;

            if (res && res.ok) {
              consecutiveFailures = 0;
              sphereRef.current.material.color.copy(reachableColor);
              lastValidPos = sphereRef.current.position.clone();
              lastValidQuat = sphereRef.current.quaternion.clone();
              emitGhostStateIfChanged();
            } else {
              consecutiveFailures++;
              sphereRef.current.material.color.copy(unreachableColor);
              if (!isDraggingTargetRef.current) {
                sphereRef.current.position.copy(lastValidPos);
                sphereRef.current.quaternion.copy(lastValidQuat);
              }
            }
          });
        };
        translateControl.addEventListener('objectChange', sendIKFromSphere);
        rotateControl.addEventListener('objectChange', sendIKFromSphere);

        const onKeyDown = (e) => {
          switch (e.key.toLowerCase()) {
            case 'l': {
              const newSpace = translateControl.space === 'local' ? 'world' : 'local';
              translateControl.setSpace(newSpace);
              rotateControl.setSpace(newSpace);
              break;
            }
            case 'g': {
              copyRealToGhost();
              break;
            }
            default: break;
          }
        };
        window.addEventListener('keydown', onKeyDown);
      }

      // Real robot joint_states subscription via rosApi
      unsubscribeJointStates = rosApi.subscribeJointStates((message) => {
        if (!robotRef.current) return;
        for (let i = 0; i < message.name.length; i++) {
          const jointName = message.name[i];
          const position = message.position[i];
          setRobotJointValue(robotRef.current, jointName, position);
        }
      });
    };
    // Fetch URDF via rosApi
    rosApi.getUrdfXml().then(loadUrdf);

    return () => {
      try { unsubscribeJointStates && unsubscribeJointStates(); } catch (_) { }
    };
  }, [rosApi?.connected]);

  // Apply preview joints -> ghost
  useEffect(() => {
    if (!ghostRef.current || !previewJoints) return;
    // Only apply if different from current ghost to avoid flip-flop
    const current = collectGhostJoints();
    if (jointsEqual(previewJoints, current)) return;
    if (previewJoints.joint_1 !== undefined) {
      jointOrder.forEach(j => {
        if (previewJoints[j] !== undefined) setRobotJointValue(ghostRef.current, j, previewJoints[j]);
      });
      // After applying preview joints to the ghost model, emit the new ghost
      // state back to the parent so `ghostJoints` stays in sync with the visual
      // model. This avoids race conditions where UI changes (eg gripper) are
      // applied as preview but never reflected in the app-level ghost state.
      try { emitGhostStateIfChanged(); } catch (e) { }
    }
  }, [previewJoints]);

  // Visibility
  useEffect(() => {
    if (robotRef.current) robotRef.current.visible = !!showRealRobot;
    if (ghostRef.current) ghostRef.current.visible = !!showGhostRobot;
  }, [showRealRobot, showGhostRobot]);

  // Control visibility of the target sphere and the TransformControls
  useEffect(() => {
    if (sphereRef.current) sphereRef.current.visible = !!showGhostRobotCoordinates;
    if (translateCtrlRef.current) {
      translateCtrlRef.current.getHelper().visible = !!showGhostRobotCoordinates;
      translateCtrlRef.current.enabled = !!showGhostRobotCoordinates;
    }
    if (rotateCtrlRef.current) {
      rotateCtrlRef.current.getHelper().visible = !!showGhostRobotCoordinates;
      rotateCtrlRef.current.enabled = !!showGhostRobotCoordinates;
    }
  }, [showGhostRobotCoordinates]);

  return (
    <div style={{ width: '100%', height: '100%', position: 'relative', margin: 0, padding: 0, overflow: 'hidden' }}>
      <div ref={mountRef} style={{ width: '100%', height: '100%', margin: 0, padding: 0, position: 'relative', overflow: 'hidden' }} />
      {showFPS && (
        <div style={{ position: 'absolute', top: '60px', left: '12px', backgroundColor: 'rgba(0, 0, 0, 0.6)', color: '#00d4aa', padding: '4px 10px', borderRadius: '6px', fontSize: '11px', fontFamily: 'monospace', zIndex: 5, pointerEvents: 'none' }}>
          FPS: {fps}
        </div>
      )}
    </div>
  );
});

export default Viewer3D;
