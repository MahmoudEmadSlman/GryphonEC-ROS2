import React, { useState, useEffect, useRef } from 'react';
import './App.css';
import { RosProvider, useROS } from './RosContext';
import Viewer3D from './components/Viewer3D';
import FKControls from './components/FKControls';
import IKControls from './components/IKControls';
import useRosApi from './ros/useRosApi';
import Accordion from '@mui/material/Accordion';
import AccordionSummary from '@mui/material/AccordionSummary';
import AccordionDetails from '@mui/material/AccordionDetails';
import ExpandMoreIcon from '@mui/icons-material/ExpandMore';
import Settings from './components/Settings';
import Fab from '@mui/material/Fab';
import SchoolIcon from '@mui/icons-material/School';
import FlipCameraAndroidIcon from '@mui/icons-material/FlipCameraAndroid';
import PrecisionManufacturingIcon from '@mui/icons-material/PrecisionManufacturing';
import Dialog from '@mui/material/Dialog';
import DialogActions from '@mui/material/DialogActions';
import DialogContent from '@mui/material/DialogContent';
import DialogContentText from '@mui/material/DialogContentText';
import DialogTitle from '@mui/material/DialogTitle';
import TextField from '@mui/material/TextField';
import Button from '@mui/material/Button';
import IconButton from '@mui/material/IconButton';
import MenuIcon from '@mui/icons-material/Menu';
import Poses from './components/Poses';
import Program from './components/Program';

/* Accordion icon mapping */
import OpenWithIcon from '@mui/icons-material/OpenWith';
import GpsFixedIcon from '@mui/icons-material/GpsFixed';
import TuneIcon from '@mui/icons-material/Tune';
import BookmarkIcon from '@mui/icons-material/Bookmark';
import PlaylistPlayIcon from '@mui/icons-material/PlaylistPlay';

function AppInner() {
  const rosApi = useRosApi();
  const { connected } = useROS();
  const defaultSettings = {
    showRealRobot: true,
    showGhostRobot: true,
    showFPS: false,
    showGhostRobotCoordinates: true,
  };

  const [activeTab, setActiveTab] = useState('forward');
  const [isSidebarOpen, setIsSidebarOpen] = useState(true);
  const [sidebarWidth, setSidebarWidth] = useState(420);
  const isResizing = useRef(false);
  const [ikPreviewJoints, setIkPreviewJoints] = useState(null);
  const [currentJoints, setCurrentJoints] = useState(null);
  const [ghostJoints, setGhostJoints] = useState(null);
  const [showRealRobot, setShowRealRobot] = useState(defaultSettings.showRealRobot);
  const [showGhostRobot, setShowGhostRobot] = useState(defaultSettings.showGhostRobot);
  const [showGhostRobotCoordinates, setShowGhostRobotCoordinates] = useState(defaultSettings.showGhostRobotCoordinates);
  const [showFPS, setShowFPS] = useState(defaultSettings.showFPS);
  const [isDialogOpen, setIsDialogOpen] = useState(false);
  const [poseName, setPoseName] = useState('');
  const [poses, setPoses] = useState(() => {
    const savedPoses = JSON.parse(localStorage.getItem('savedPoses')) || [];
    return savedPoses;
  });
  const posesRef = useRef(null); // Reference to the Poses component
  const urdfApiRef = useRef(null);

  // When the program panel opens/closes or sidebar toggles, force the 3D viewer to resize so it adapts to the new width
  useEffect(() => {
    try {
      if (urdfApiRef.current && typeof urdfApiRef.current.forceResize === 'function') {
        // small timeout to let CSS transition complete
        setTimeout(() => {
          try { urdfApiRef.current.forceResize(); } catch (e) {}
        }, 260);
      }
    } catch (e) {}
  }, [activeTab, isSidebarOpen, sidebarWidth]);

  // Handle sidebar resizing
  const startResizing = React.useCallback(() => {
    isResizing.current = true;
    document.body.style.cursor = 'col-resize';
    
    const handleMouseMove = (e) => {
      if (!isResizing.current) return;
      const newWidth = e.clientX;
      if (newWidth >= 320 && newWidth <= 800) {
        setSidebarWidth(newWidth);
      }
    };
    
    const handleMouseUp = () => {
      isResizing.current = false;
      document.body.style.cursor = '';
      document.removeEventListener('mousemove', handleMouseMove);
      document.removeEventListener('mouseup', handleMouseUp);
      // force 3D resize
      if (urdfApiRef.current && typeof urdfApiRef.current.forceResize === 'function') {
        setTimeout(() => urdfApiRef.current.forceResize(), 100);
      }
    };

    document.addEventListener('mousemove', handleMouseMove);
    document.addEventListener('mouseup', handleMouseUp);
  }, []);

  const [showOverlay, setShowOverlay] = useState(false);
  const [overlayRealTCP, setOverlayRealTCP] = useState(null);
  const [overlayGhostTCP, setOverlayGhostTCP] = useState(null);

  const jointOrder = ['joint_1','joint_2','joint_3','joint_4','joint_5'];
  const radToDeg = (r) => (r * 180 / Math.PI);

  // Formatters for overlay display
  const formatArmJoints = (joints) => {
    if (!joints) return 'N/A';
    try {
      const vals = jointOrder.map((n) => {
        const v = joints[n];
        if (v === undefined || v === null) return 'N/A';
        return `${radToDeg(v).toFixed(1)}°`;
      });
      return vals.join(', ');
    } catch (e) { return 'N/A'; }
  };

  // Gripper is special: invert sign and show as absolute value
  const formatGripper = (joints) => {
    if (!joints) return 'N/A';
    const g = joints['gripperbase_to_armgearright'];
    if (g === undefined || g === null) return 'N/A';
    return `${Math.round(Math.abs(radToDeg(g)))}°`;
  };

  // Position and orientation formatting
  const formatPosition = (tcp) => {
    if (!tcp) return 'N/A';
    const { x, y, z } = tcp;
    const factor = (Math.abs(x) < 10 && Math.abs(y) < 10 && Math.abs(z) < 10) ? 1000 : 1;
    return `${(x*factor).toFixed(1)}mm, ${(y*factor).toFixed(1)}mm, ${(z*factor).toFixed(1)}mm`;
  };

  // Orientation as quaternion
  const formatOrientation = (tcp) => {
    if (!tcp) return 'N/A';
    const { qx, qy, qz, qw } = tcp;
    return `${(qx||0).toFixed(1)}, ${(qy||0).toFixed(1)}, ${(qz||0).toFixed(1)}, ${(qw||0).toFixed(1)}`;
  };

  // Subscribe to /joint_states to obtain current joint positions
  useEffect(() => {
    if (!rosApi.connected) return;
    let previousJoints = null;
    const unsubscribe = rosApi.subscribeJointStates((msg) => {
      const joints = {};
      msg.name.forEach((name, i) => {
        joints[name] = parseFloat(msg.position[i].toFixed(4));
      });
      if (JSON.stringify(previousJoints) !== JSON.stringify(joints)) {
        setCurrentJoints(joints);
        previousJoints = joints;
      }
    });
    return () => {
      try { unsubscribe && unsubscribe(); } catch (_) {}
    };
  }, [rosApi.connected]);

  // Open the "Save Pose" dialog
  const openSavePoseDialog = () => {
    setIsDialogOpen(true);
  };

  // Close the "Save Pose" dialog
  const handleDialogClose = () => {
    setIsDialogOpen(false);
  };

  // Save the new pose
  const handleSavePose = () => {
    if (poseName.trim() === '') {
      alert('Pose name is required!');
      return;
    }

    // Check for duplicate pose name
    const isDuplicate = poses.some(pose => pose.name === poseName.trim());
    if (isDuplicate) {
      alert('A pose with this name already exists. Please choose a different name.');
      return;
    }

    // Get current TCP coordinates from the real robot
    let currentTCP = null;
    if (urdfApiRef.current && typeof urdfApiRef.current.getTCPFromJoints === 'function' && currentJoints) {
      try {
        currentTCP = urdfApiRef.current.getTCPFromJoints(currentJoints);
        console.log('Current TCP coordinates obtained:', currentTCP);
      } catch (error) {
        console.error('Error getting TCP coordinates:', error);
      }
    }

    const poseData = {
      name: poseName,
      joints: Object.fromEntries(
        ['joint_1', 'joint_2', 'joint_3', 'joint_4', 'joint_5', 'gripperbase_to_armgearright'].map(jointName => [jointName, currentJoints[jointName]])
      ),
      gripperBase: currentTCP
    };

    const updatedPoses = [...poses, poseData];
    setPoses(updatedPoses);
    localStorage.setItem('savedPoses', JSON.stringify(updatedPoses));

    if (posesRef.current) {
      posesRef.current.updatePoses();
    }

    setIsDialogOpen(false);
    setPoseName('');
  };

  // Compute the effective preview joints: when in forward kinematics, we clear the IK preview.
  const effectivePreviewJoints = activeTab === 'forward' ? null : ikPreviewJoints;

  // Memoized callback to pass to Poses for previewing joints
  const memoizedOnPreviewJointsChange = React.useCallback((joints) => setIkPreviewJoints(joints), []);

  // Keep overlay TCP values in sync. Try to use urdfApi methods when available.
  useEffect(() => {
    let mounted = true;
    const update = async () => {
      const api = urdfApiRef.current;
      if (!api) return;
      try {
        // Real TCP: prefer computing from currentJoints
        if (currentJoints && typeof api.getTCPFromJoints === 'function') {
          const t = api.getTCPFromJoints(currentJoints);
          if (mounted) setOverlayRealTCP(t || null);
        }
        // Ghost TCP: prefer explicit ghost state or compute from ghost joints
        if (ghostJoints && typeof api.getTCPFromJoints === 'function') {
          const tg = api.getTCPFromJoints(ghostJoints);
          if (mounted) setOverlayGhostTCP(tg || null);
        } else if (typeof api.getGhostState === 'function') {
          const s = api.getGhostState && api.getGhostState();
          if (s && s.tcp && mounted) setOverlayGhostTCP(s.tcp);
        }
      } catch (e) {
        // ignore
      }
    };
    update();
    const id = setInterval(update, 300);
    return () => { mounted = false; clearInterval(id); };
  }, [currentJoints, ghostJoints]);

  return (
      <div className="app-container" style={{ display: 'flex', height: '100vh', position: 'relative' }}>
        
        {/* Toggle Sidebar Button (always visible on top left of the screen) */}
        <IconButton 
          onClick={() => setIsSidebarOpen(!isSidebarOpen)}
          sx={{ 
            position: 'absolute', 
            top: '12px', 
            left: '12px', 
            zIndex: 100, 
            backgroundColor: 'rgba(17, 24, 39, 0.8)', 
            backdropFilter: 'blur(8px)',
            color: '#00d4aa',
            border: '1px solid rgba(0, 212, 170, 0.3)',
            '&:hover': { backgroundColor: 'rgba(0, 212, 170, 0.2)' }
          }}
        >
          <MenuIcon />
        </IconButton>

  {/* Left sidebar */}
  <div className={'sidebar'} style={{ display: isSidebarOpen ? 'flex' : 'none', width: sidebarWidth, minWidth: sidebarWidth, maxWidth: sidebarWidth }}>
    <div className="sidebar-top">
      <div className="logo-section">
        <img src="/images/thor_logo.png" alt="Thor Logo" />
        <div className="logo-subtitle">Robotic Arm Control</div>
        <div className={`connection-status ${connected ? 'connected' : 'disconnected'}`}>
          <span className={`status-dot ${connected ? 'connected' : 'disconnected'}`}></span>
          {connected ? 'ROS Connected' : 'ROS Disconnected'}
        </div>
      </div>
    </div>
    {/* Bottom: accordions (scrollable) */}
    <div className="sidebar-bottom">
      {/* Accordions */}
      <Accordion
            expanded={activeTab === 'forward'}
            onChange={() => setActiveTab(activeTab === 'forward' ? '' : 'forward')}
            className="accordion forward-kinematics"
          >
            <AccordionSummary className='accordion-summary' expandIcon={<ExpandMoreIcon className="expand-icon" />}> 
              <span className="accordion-title">
                <OpenWithIcon className="accordion-icon" />
                Forward Kinematics
              </span>
            </AccordionSummary>
            <AccordionDetails>
              <FKControls initialJoints={ghostJoints} urdfApi={urdfApiRef.current} active={activeTab === 'forward'} />
            </AccordionDetails>
          </Accordion>

          <Accordion
            expanded={activeTab === 'inverse'}
            onChange={() => {
              const newTab = activeTab === 'inverse' ? '' : 'inverse';
              setActiveTab(newTab);
            }}
            className="accordion inverse-kinematics"
          >
            <AccordionSummary className='accordion-summary' expandIcon={<ExpandMoreIcon className="expand-icon" />}> 
              <span className="accordion-title">
                <GpsFixedIcon className="accordion-icon" />
                Inverse Kinematics
              </span>
            </AccordionSummary>
            <AccordionDetails>
              <IKControls
                onPreviewJointsChange={setIkPreviewJoints}
                ghostJoints={ghostJoints}
                urdfApi={urdfApiRef.current}
                active={activeTab === 'inverse'}
              />
            </AccordionDetails>
          </Accordion>

          <Accordion
            expanded={activeTab === 'settings'}
            onChange={() => setActiveTab(activeTab === 'settings' ? '' : 'settings')}
            className="accordion settings"
          >
            <AccordionSummary
              className='accordion-summary'
              expandIcon={<ExpandMoreIcon className="expand-icon" />}
            >
              <span className="accordion-title">
                <TuneIcon className="accordion-icon" />
                Settings
              </span>
            </AccordionSummary>
            <AccordionDetails>
              <Settings
                showRealRobot={showRealRobot}
                setShowRealRobot={setShowRealRobot}
                showFPS={showFPS}
                setShowFPS={setShowFPS}
                showGhostRobot={showGhostRobot}
                setShowGhostRobot={setShowGhostRobot}
                showTcpGizmo={showGhostRobotCoordinates}
                setShowTcpGizmo={setShowGhostRobotCoordinates}
                showRobotState={showOverlay}
                setShowRobotState={setShowOverlay}
              />
            </AccordionDetails>
          </Accordion>

          <Accordion
            expanded={activeTab === 'poses'}
            onChange={() => setActiveTab(activeTab === 'poses' ? '' : 'poses')}
            className="accordion poses"
          >
            <AccordionSummary
              className='accordion-summary'
              expandIcon={<ExpandMoreIcon className="expand-icon" />}
            >
              <span className="accordion-title">
                <BookmarkIcon className="accordion-icon" />
                Poses
              </span>
            </AccordionSummary>
            <AccordionDetails>
              <Poses ref={posesRef} onPreviewJointsChange={memoizedOnPreviewJointsChange} poses={poses} setPoses={setPoses} />
            </AccordionDetails>
          </Accordion>

          <Accordion
            expanded={activeTab === 'program'}
            onChange={() => setActiveTab(activeTab === 'program' ? '' : 'program')}
            className="accordion program"
          >
            <AccordionSummary
              className='accordion-summary'
              expandIcon={<ExpandMoreIcon className="expand-icon" />}
            >
              <span className="accordion-title">
                <PlaylistPlayIcon className="accordion-icon" />
                Program
              </span>
            </AccordionSummary>
            <AccordionDetails>
              <Program poses={poses} />
            </AccordionDetails>
          </Accordion>
    </div>
  </div>

  {/* Resizer Handle (Flex Sibling) */}
  {isSidebarOpen && (
    <div className="resizer" onMouseDown={startResizing}></div>
  )}

        <div style={{ flex: 1, display: 'flex', flexDirection: 'column', position: 'relative', minHeight: 0 }}>
          <div style={{ flex: '1 1 auto', minHeight: 0, overflow: 'hidden' }}>
            <Viewer3D
              ref={urdfApiRef}
              previewJoints={effectivePreviewJoints}
              showRealRobot={showRealRobot}
              showGhostRobot={showGhostRobot}
              onGhostJointsChange={setGhostJoints}
              className="urdf-viewer"
              showFPS={showFPS}
              showGhostRobotCoordinates={showGhostRobotCoordinates}
              rosApi={rosApi}
            />
          </div>

          {showOverlay && (
            <div style={{ position: 'absolute', bottom: '12px', left: '12px', right: '200px', zIndex: 11, display: 'flex', justifyContent: 'center' }}>
              <div id="robot-state-overlay" style={{ width: '100%', maxWidth: '1100px' }}>
                <div className="overlay-row">
                  <span className="overlay-label real">Real Robot</span>
                  <span className="overlay-value">
                    <strong>Joints:</strong> {formatArmJoints(currentJoints)} &nbsp;·&nbsp;
                    <strong>Gripper:</strong> {formatGripper(currentJoints)} &nbsp;·&nbsp;
                    <strong>Pos:</strong> {formatPosition(overlayRealTCP)} &nbsp;·&nbsp;
                    <strong>Orient:</strong> {formatOrientation(overlayRealTCP)}
                  </span>
                </div>
                <div className="overlay-separator"></div>
                <div className="overlay-row">
                  <span className="overlay-label ghost">Ghost Robot</span>
                  <span className="overlay-value">
                    <strong>Joints:</strong> {formatArmJoints(ghostJoints)} &nbsp;·&nbsp;
                    <strong>Gripper:</strong> {formatGripper(ghostJoints)} &nbsp;·&nbsp;
                    <strong>Pos:</strong> {formatPosition(overlayGhostTCP)} &nbsp;·&nbsp;
                    <strong>Orient:</strong> {formatOrientation(overlayGhostTCP)}
                  </span>
                </div>
              </div>
            </div>
          )}
        </div>

        {/* FAB Buttons Container */}
        <div className="fab-container">
          {/* TCP Gizmo Frame FAB */}
          {showGhostRobotCoordinates && (
            <Fab variant="extended"
              aria-label="toggle-tcp-gizmo"
              onClick={() => { if (urdfApiRef.current && urdfApiRef.current.toggleTCPGizmoFrame) urdfApiRef.current.toggleTCPGizmoFrame(); }}
            >
              <FlipCameraAndroidIcon style={{ marginRight: '8px' }} />
              TCP Gizmo
            </Fab>
          )}

          {/* Move Ghost to Real FAB */}
          {showGhostRobot && (
            <Fab variant="extended"
              aria-label="move-ghost-to-real"
              onClick={() => { if (urdfApiRef.current && urdfApiRef.current.copyRealToGhost) urdfApiRef.current.copyRealToGhost(); }}
            >
              <PrecisionManufacturingIcon style={{ marginRight: '8px' }} />
              Ghost → Real
            </Fab>
          )}

          {/* Teach Real Pose FAB */}
          <Fab variant="extended"
            aria-label="teach-pose"
            onClick={openSavePoseDialog}
          >
            <SchoolIcon style={{ marginRight: '8px' }} />
            Teach Pose
          </Fab>
        </div>

        {/* Form Dialog */}
        <Dialog open={isDialogOpen} onClose={handleDialogClose}>
          <DialogTitle>Save Pose</DialogTitle>
          <DialogContent>
            <DialogContentText>
              Enter a name for the pose:
            </DialogContentText>
            <TextField
              autoFocus
              margin="dense"
              label="Pose Name"
              type="text"
              fullWidth
              inputProps={{ maxLength: 12 }}
              value={poseName}
              onChange={(e) => setPoseName(e.target.value)}
            />
          </DialogContent>
          <DialogActions>
            <Button onClick={handleDialogClose} color="secondary">
              Cancel
            </Button>
            <Button onClick={handleSavePose} color="primary">
              Save
            </Button>
          </DialogActions>
        </Dialog>
      </div>
  );
}

function App() {
  return (
    <RosProvider>
      <AppInner />
    </RosProvider>
  );
}

export default App;