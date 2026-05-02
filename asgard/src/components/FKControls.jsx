import React, { useState, useEffect, useRef } from 'react';
import { useROS } from '../RosContext';
import Slider from '@mui/material/Slider';
import Button from '@mui/material/Button';
import Input from '@mui/material/Input';

const jointConfigs = [
  { name: 'joint_1', label: 'Joint 1', min: -180, max: 180 },
  { name: 'joint_2', label: 'Joint 2', min: -90, max: 90 },
  { name: 'joint_3', label: 'Joint 3', min: -120, max: 120 },
  { name: 'joint_4', label: 'Joint 4', min: -120, max: 120 },
  { name: 'joint_5', label: 'Joint 5', min: -180, max: 180 },
  { name: 'gripperbase_to_armgearright', label: 'Gripper', min: -28.6, max: 43.0 }
];

function FKControls({ initialJoints, urdfApi, active = true }) {
  const { connected } = useROS();
  const suppressSyncRef = useRef(false);
  const [jointValuesDeg, setJointValuesDeg] = useState(
    jointConfigs.reduce((acc, joint) => {
      acc[joint.name] = "0";
      return acc;
    }, {})
  );

  // Initialize joint values from initialJoints prop (in radians), converting to degrees
  useEffect(() => {
    if (initialJoints) {
      setJointValuesDeg(prev => {
        const newValuesDeg = { ...prev };
        jointConfigs.forEach(cfg => {
          if (initialJoints[cfg.name] !== undefined) {
            let val = Math.round((initialJoints[cfg.name] * 180) / Math.PI * 100) / 100;
            if (cfg.name === 'gripperbase_to_armgearright') val = -val;
            newValuesDeg[cfg.name] = val.toString();
          }
        });
        return newValuesDeg;
      });
    suppressSyncRef.current = true;
    }
  }, [initialJoints]);

  // Update the ghost via the API only on user-initiated changes
  useEffect(() => {
    if (suppressSyncRef.current) {
      suppressSyncRef.current = false;
      return;
    }
     const jointsRad = {};
    jointConfigs.forEach(cfg => { 
      const valNum = parseFloat(jointValuesDeg[cfg.name]) || 0;
      jointsRad[cfg.name] = (valNum * Math.PI) / 180; 
    });
    jointsRad['gripperbase_to_armgearright'] = -jointsRad['gripperbase_to_armgearright'];
    if (active && urdfApi) {
      urdfApi.setGhostJoints(jointsRad);
      if (urdfApi.syncTargetToTCP) urdfApi.syncTargetToTCP();
    }
  }, [jointValuesDeg, urdfApi, active]);

  // Handle slider change
  const handleJointSliderChange = (name, value) => {
    setJointValuesDeg(prev => ({ ...prev, [name]: value.toFixed(1) }));
  };

  // Ensure input is numeric and within bounds, but allow intermediate states like "-"
  const handleJointInputChange = (name, value, min, max) => {
    // Allow empty or just a minus sign for typing
    if (value === '' || value === '-') {
      setJointValuesDeg(prev => ({ ...prev, [name]: value }));
      return;
    }

    let valueNum = parseFloat(value);
    if (isNaN(valueNum)) return; // ignore invalid numeric strings that aren't "-"

    // Clamp values
    if (valueNum > max) valueNum = max;
    if (valueNum < min) valueNum = min;
    
    // Store as string to maintain user formatting/typing
    setJointValuesDeg(prev => ({ ...prev, [name]: valueNum.toString() }));
  };

  // Publish the ghost to the robot controller
  const publishGhostToController = () => {
    if (!connected || !urdfApi) return;
    urdfApi.publishGhostToController();
  };

  return (
    <div style={{ marginTop: '0' }}>
      {jointConfigs.map(joint => (
        <div key={joint.name} className="fk-joint-row">
          <label htmlFor={joint.name} className="fk-joint-label">
            {joint.label}
          </label>
          <Slider id={joint.name} min={joint.min} max={joint.max} step={0.1} value={parseFloat(jointValuesDeg[joint.name]) || 0} onChange={(e, value) => handleJointSliderChange(joint.name, value)} style={{ flex: 1, marginLeft: '-20px' }} />
          <Input value={jointValuesDeg[joint.name]} onChange={e => handleJointInputChange(joint.name, e.target.value, joint.min, joint.max)} inputProps={{ step: 0.1, min: joint.min, max: joint.max, type: 'text', 'aria-labelledby': joint.name }} style={{ width: '72px' }} />
          <span className="fk-joint-unit">°</span>
        </div>
      ))}
      <Button className="move-j-btn" variant="contained" onClick={publishGhostToController} style={{ marginTop: '1rem', display: 'block', marginLeft: 'auto', marginRight: 'auto' }}>
        Move
      </Button>
    </div>
  );
}

export default FKControls;