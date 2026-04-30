import React, { useState, useEffect, useRef } from 'react';
import { useROS } from '../RosContext';
import Button from '@mui/material/Button';
import ButtonGroup from '@mui/material/ButtonGroup';
import * as THREE from 'three';
import useRosApi from '../ros/useRosApi';

export default function IKControls({
  ikPose: ikTargetPose,
  onPreviewJointsChange: onPreviewJointsUpdate,
  onIKStatusChange: onIKReachabilityChange,
  ghostJoints,
  urdfApi,
  active = true,
}) {
  const { connected } = useROS();
  const rosApi = useRosApi();

  // Main state: TCP position and orientation
  const [tcpPosition, setTcpPosition] = useState(new THREE.Vector3(200, 0, 300)); // in mm
  const [tcpQuaternion, setTcpQuaternion] = useState(new THREE.Quaternion(0, 0, 0, 1)); // identity
  const suppressNextSolveRef = useRef(false);

  // State for cartesian movement
  const [cartesianError, setCartesianError] = useState('');
  const [isComputingCartesian, setIsComputingCartesian] = useState(false);

  // When the IK tab becomes active, sync with the ghost's current TCP
  useEffect(() => {
    if (!active) return;
    if (!urdfApi) return;
    const state = urdfApi.getGhostState && urdfApi.getGhostState();
    if (state && state.tcp) {
      suppressNextSolveRef.current = true; // prevent triggering IK solve from this sync
      setTcpPosition(new THREE.Vector3(state.tcp.x, state.tcp.y, state.tcp.z));
      setTcpQuaternion(new THREE.Quaternion(state.tcp.qx, state.tcp.qy, state.tcp.qz, state.tcp.qw));
    }
  }, [active, urdfApi]);
  
  const [gripperPercent, setGripperPercent] = useState(0);

  // Update gripper percent state
  const updateGripperPercent = (value) => {
    console.warn('Gripper control changed, new percent:', value);
    setGripperPercent(value);
  };
  
  const continuousMoveIntervalRef = useRef(null);
  const ghostJointsRef = useRef(null);

  // keep a ref to the latest ghostJoints so we can update gripper only when user changes it
  useEffect(() => { ghostJointsRef.current = ghostJoints; }, [ghostJoints]);

  // Initialize only when `ikPose` changes
  useEffect(() => {
    if (ikTargetPose) {
      setTcpPosition(new THREE.Vector3(
        Math.round(ikTargetPose.x),
        Math.round(ikTargetPose.y),
        Math.round(ikTargetPose.z)
      ));
      if (
        ikTargetPose.qx !== undefined &&
        ikTargetPose.qy !== undefined &&
        ikTargetPose.qz !== undefined &&
        ikTargetPose.qw !== undefined
      ) {
        setTcpQuaternion(new THREE.Quaternion(
          ikTargetPose.qx,
          ikTargetPose.qy,
          ikTargetPose.qz,
          ikTargetPose.qw
        ));
      }
    }
  }, [ikTargetPose]);

  // IK requests (when position or quaternion change) => delegate to urdfApi
  useEffect(() => {
    if (!active) return; // only when the tab is active
    if (!urdfApi || !connected) return;
    if (suppressNextSolveRef.current) { // avoid re-triggering IK if this is an external sync
      suppressNextSolveRef.current = false;
      return;
    }
    const pose = {
      x: tcpPosition.x,
      y: tcpPosition.y,
      z: tcpPosition.z,
      qx: tcpQuaternion.x,
      qy: tcpQuaternion.y,
      qz: tcpQuaternion.z,
      qw: tcpQuaternion.w,
    };
    urdfApi.solveAndMoveToPose(pose).then((res) => {
      if (res && res.ok) {
        if (onPreviewJointsUpdate) onPreviewJointsUpdate(res.joints);
        if (onIKReachabilityChange) onIKReachabilityChange('reachable');
        // Align the visual target/sphere with the newly solved TCP
        if (urdfApi.syncTargetToTCP) urdfApi.syncTargetToTCP();
      } else {
        if (onPreviewJointsUpdate) onPreviewJointsUpdate({});
        if (onIKReachabilityChange) onIKReachabilityChange('unreachable');
      }
    });
  }, [tcpPosition, tcpQuaternion, urdfApi, connected, active]);

  // Sync the UI with the ghost's TCP when the ghost changes
  useEffect(() => {
    if (!active) return;
    if (!urdfApi || !ghostJoints) return;
    const state = urdfApi.getGhostState && urdfApi.getGhostState();
    if (state && state.tcp) {
      const { x, y, z, qx, qy, qz, qw } = state.tcp;
      // Avoid loop: flag to prevent launching IK in the next effect
      suppressNextSolveRef.current = true;
      setTcpPosition(new THREE.Vector3(x, y, z));
      setTcpQuaternion(new THREE.Quaternion(qx, qy, qz, qw));
    }
  }, [ghostJoints, active, urdfApi]);

  // Publish the ghost to the robot controller
  const publishGhostToController = () => {
    if (!urdfApi) return;
    urdfApi.publishGhostToController();
  };

  // Execute cartesian move to the current TCP position
  const executeCartesianMove = async () => {
    if (!urdfApi || !rosApi.connected) return;
    
    setIsComputingCartesian(true);
    setCartesianError('');

    try {
      // Get current TCP pose from ghost
      const currentState = urdfApi.getGhostState && urdfApi.getGhostState();
      if (!currentState || !currentState.tcp) {
        setCartesianError('Could not get current TCP position');
        setIsComputingCartesian(false);
        return;
      }

      const startPose = {
        x: currentState.tcp.x,
        y: currentState.tcp.y,
        z: currentState.tcp.z,
        qx: currentState.tcp.qx,
        qy: currentState.tcp.qy,
        qz: currentState.tcp.qz,
        qw: currentState.tcp.qw,
      };

      const endPose = {
        x: tcpPosition.x,
        y: tcpPosition.y,
        z: tcpPosition.z,
        qx: tcpQuaternion.x,
        qy: tcpQuaternion.y,
        qz: tcpQuaternion.z,
        qw: tcpQuaternion.w,
      };

      // Compute gripper value from local gripperPercent to avoid race with ghostJoints updates
      // Map gripperPercent (0-100) to radians (0.5 to -0.75)
      let gripperRadians;
      if (gripperPercent === 0) {
        gripperRadians = 0.5;
      } else if (gripperPercent === 100) {
        gripperRadians = -0.75;
      } else {
        gripperRadians = 0.5 - (1.25 * (gripperPercent / 100));
      }

      // Use the locally computed value to ensure we send what the user selected
      const currentGripperValue = gripperRadians;

      // Warn the gripper value (percent and radians) that will be sent with the cartesian goal
      console.warn('MOVE L - gripper percent:', gripperPercent, '->', currentGripperValue);

      // Send cartesian goal to ROS
      const cartesianResult = await rosApi.publishCartesianGoal(startPose, endPose, {
        gripperValue: currentGripperValue
      });
      
      if (!cartesianResult.ok) {
        if (cartesianResult.error === 'timeout') {
          setCartesianError('Cartesian movement timeout');
        } else {
          setCartesianError(cartesianResult.message || 'No cartesian solution found');
        }
        setIsComputingCartesian(false);
        return;
      }

      // Success
      console.log('Cartesian movement completed successfully');
      console.log('Waypoints:', cartesianResult.waypoints);

    } catch (error) {
      console.error('Cartesian move error:', error);
      setCartesianError('Error during cartesian movement');
    } finally {
      setIsComputingCartesian(false);
    }
  };

  // Apply delta in world/global coordinates
  const applyWorldDelta = (axis, increment) => {
    if (axis === 'x' || axis === 'y' || axis === 'z') {
      // Linear global movement (no transform)
      setTcpPosition(prevPos => {
        const newPos = prevPos.clone();
        newPos[axis] += increment; // mm in global coordinates
        return newPos;
      });
    } else {
      // Rotation: fixed global axes (no transform)
      setTcpQuaternion(prevQuat => {
        let rotAxis;
        if (axis === 'roll') rotAxis = new THREE.Vector3(1, 0, 0);
        if (axis === 'pitch') rotAxis = new THREE.Vector3(0, 1, 0);
        if (axis === 'yaw') rotAxis = new THREE.Vector3(0, 0, 1);

        // Create incremental rotation quaternion in global axes
        const deltaQ = new THREE.Quaternion().setFromAxisAngle(rotAxis, increment * Math.PI / 180);

        // Apply global rotation
        return prevQuat.clone().premultiply(deltaQ);
      });
    }
  };

  // Apply delta in TCP local coordinates
  const applyTcpDelta = (axis, increment) => {
    if (axis === 'x' || axis === 'y' || axis === 'z') {
      // Linear movement: transform delta by current quaternion (local coordinates)
      setTcpPosition(prevPos => {
        const localDelta = new THREE.Vector3();
        localDelta[axis] = increment; // mm
        localDelta.applyQuaternion(tcpQuaternion); // transform to global coordinates
        return prevPos.clone().add(localDelta);
      });
    } else {
      // Rotation: use pure quaternions
      setTcpQuaternion(prevQuat => {
        const q = prevQuat.clone();
        let rotAxis;
        if (axis === 'roll') rotAxis = new THREE.Vector3(1, 0, 0);
        if (axis === 'pitch') rotAxis = new THREE.Vector3(0, 1, 0);
        if (axis === 'yaw') rotAxis = new THREE.Vector3(0, 0, 1);

        // Transform axis to current local coordinates
        rotAxis.applyQuaternion(q);

        // Create incremental rotation quaternion
        const deltaQ = new THREE.Quaternion().setFromAxisAngle(rotAxis, increment * Math.PI / 180);

        // Apply rotation
        return q.premultiply(deltaQ);
      });
    }
  };

  // Start continuous movement in the given axis and direction
  const startContinuousMove = (axis, increment, frameType = 'tcp') => {
    const moveFunction = frameType === 'world' ? applyWorldDelta : applyTcpDelta;
    const intervalId = setInterval(() => moveFunction(axis, increment), 100); // Runs every 100ms
    continuousMoveIntervalRef.current = intervalId;
  };

  // Stop continuous movement
  const stopContinuousMove = () => {
    if (continuousMoveIntervalRef.current) {
      clearInterval(continuousMoveIntervalRef.current);
      continuousMoveIntervalRef.current = null;
    }
  };

  // Sync the gripper position with the ghost's state
  useEffect(() => {
    const currentGhost = ghostJointsRef.current;
    if (!currentGhost || typeof onPreviewJointsUpdate !== 'function') return;
    const gripperValue = gripperPercent === 0
      ? 0.5
      : gripperPercent === 100
      ? -0.75
      : (0.5 - (1.25 * (gripperPercent / 100)));
    if (currentGhost['gripperbase_to_armgearright'] !== gripperValue) {
      const updatedJoints = { ...currentGhost, gripperbase_to_armgearright: gripperValue };
      onPreviewJointsUpdate(updatedJoints);
    }
  }, [gripperPercent, onPreviewJointsUpdate]);

  /* Helper to render a row of axis buttons (position or rotation) */
  const renderAxisRow = (axes, frameType) => (
    <div style={{ display: 'flex', justifyContent: 'center', gap: '1rem', marginBottom: '0.75rem' }}>
      {axes.map(({ axis, label }) => {
        const colorClass = (axis === 'x' || axis === 'roll') ? 'x' : (axis === 'y' || axis === 'pitch') ? 'y' : 'z';
        return (
          <div key={axis} style={{ display: 'flex', flexDirection: 'column', alignItems: 'center' }}>
            <label className={`axis-label axis-label-${colorClass}`}>{label}</label>
            <ButtonGroup size="small">
              <Button
                variant="contained"
                className={`axis-btn-${colorClass}`}
                onMouseDown={() => startContinuousMove(axis, -1, frameType)}
                onMouseUp={stopContinuousMove}
                onMouseLeave={stopContinuousMove}
              >−</Button>
              <Button
                variant="contained"
                className={`axis-btn-${colorClass}`}
                onMouseDown={() => startContinuousMove(axis, 1, frameType)}
                onMouseUp={stopContinuousMove}
                onMouseLeave={stopContinuousMove}
              >+</Button>
            </ButtonGroup>
          </div>
        );
      })}
    </div>
  );

  return (
    <div style={{ display: 'flex', flexDirection: 'column', alignItems: 'center', justifyContent: 'center', marginTop: '0', marginBottom: '0.5rem' }}>
      
      <div className="control-section-title">World Frame</div>
      {renderAxisRow([
        { axis: 'x', label: 'X' },
        { axis: 'y', label: 'Y' },
        { axis: 'z', label: 'Z' },
      ], 'world')}
      {renderAxisRow([
        { axis: 'roll', label: 'Roll' },
        { axis: 'pitch', label: 'Pitch' },
        { axis: 'yaw', label: 'Yaw' },
      ], 'world')}

      <div className="control-section-title">TCP Frame</div>
      {renderAxisRow([
        { axis: 'x', label: 'X' },
        { axis: 'y', label: 'Y' },
        { axis: 'z', label: 'Z' },
      ], 'tcp')}
      {renderAxisRow([
        { axis: 'roll', label: 'Roll' },
        { axis: 'pitch', label: 'Pitch' },
        { axis: 'yaw', label: 'Yaw' },
      ], 'tcp')}

      {/* Gripper control buttons */}
      <div className="control-section-title">Gripper</div>
      <ButtonGroup size="small" style={{ marginBottom: '1rem' }}>
        {[0, 20, 40, 60, 80, 100].map((percentage) => (
          <Button
            key={percentage}
            variant={gripperPercent === percentage ? "contained" : "outlined"}
            className={`gripper-btn${gripperPercent === percentage ? ' active' : ''}`}
            onClick={() => updateGripperPercent(percentage)}
          >
            {percentage}%
          </Button>
        ))}
      </ButtonGroup>

      <div style={{ display: 'flex', justifyContent: 'center', gap: '0.75rem', marginTop: '0.5rem' }}>
        <Button
          className="move-j-btn"
          onClick={publishGhostToController}
          disabled={!ghostJoints || Object.keys(ghostJoints).length === 0}
          variant="contained"
        >
          MOVE J
        </Button>

        <Button
          className="move-l-btn"
          onClick={executeCartesianMove}
          disabled={!ghostJoints || Object.keys(ghostJoints).length === 0 || !connected || isComputingCartesian}
          variant="contained"
        >
          {isComputingCartesian ? 'COMPUTING...' : 'MOVE L'}
        </Button>
      </div>

      {cartesianError && (
        <div style={{ color: '#ff4757', marginTop: '0.5rem', fontSize: '0.85rem', textAlign: 'center', background: 'rgba(255,71,87,0.08)', padding: '6px 12px', borderRadius: '8px', border: '1px solid rgba(255,71,87,0.2)' }}>
          {cartesianError}
        </div>
      )}

    </div>
  );
}