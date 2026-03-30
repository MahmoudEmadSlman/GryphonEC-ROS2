<h1 align="center">GRYPHON x ROS</h1>

<p align="center">
  <em>This repository brings together all the <b>ROS2 packages</b> required to control the <b>Gryphon robotic arm</b> using <b>ROS2 Humble</b> and <b>MoveIt2</b>.<br>
  It also includes <b>Asgard</b>, a modern web-based graphical interface built with <b>React</b> to make operating and programming the arm intuitive and accessible.</em>
</p>

<p align="center">
  <a href="https://www.ros.org/">
    <img height="100px" alt="ROS Humble Logo" src="Docs/Media/humble_logo.png" style="margin-right: 24px;">
  </a>
  <a href="https://moveit.picknik.ai/main/index.html">
    <img height="100px" alt="MoveIt2 Logo" src="Docs/Media/moveit_logo.png" style="margin-right: 24px;">
  </a>
  <a href="https://react.dev/">
    <img height="100px" alt="React Logo" src="Docs/Media/react_logo.png">
  </a>
</p>

---

## 📦 What's inside this repository?

- `ws_thor/src` — **ROS2 Packages for Gryphon**  
  All packages and configuration needed to integrate the Gryphon arm with ROS2 Humble LTS and MoveIt2, enabling motion planning, simulation, and real hardware control via RViz.

- `/asgard` — **Asgard: Web GUI**  
  A React-based web application for visual and intuitive control of the Gryphon arm — no command-line interaction needed.  
  Control the robot using joint movements (forward kinematics) or target coordinates (inverse kinematics), save poses, and create motion programs.

---

## 🤖 About the Gryphon Arm

The Gryphon is a 5-DOF robotic arm controlled via **Arduino Mega** over serial communication.  
This project adapts the arm for full ROS2 integration including simulation and real hardware execution.

**Hardware stack:**
- Gryphon robotic arm (×2)
- Arduino Mega (custom firmware)

---

## 🚀 Quick Start

### Ubuntu 22.04

👉 [See instructions for Ubuntu 22.04](ubuntu-instructions.md)

---

## 🏗️ Project Roadmap

- [x] URDF / XACRO model
- [x] MoveIt2 motion planning
- [x] RViz simulation
- [ ] Asgard web GUI integration
- [ ] Arduino hardware interface (ros2_control)
- [ ] Dual-arm coordination

---

## 🤝 Acknowledgements

This project is built on top of [Thor-ROS](https://github.com/AngelLM/Thor-ROS) by [Angel LM](https://github.com/AngelLM), used with permission.  
Licensed under [CC BY-SA 4.0](https://creativecommons.org/licenses/by-sa/4.0/).

---

## 📄 License

This repository is licensed under the **Creative Commons Attribution-ShareAlike 4.0 International** license.  
See [LICENSE](LICENSE) for full details.
