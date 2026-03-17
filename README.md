# BB8 Bluetooth-Controlled Robot (Freshman Design Project)

This project was developed for a freshman engineering design competition at the University of Hartford, focused on integrating mechanical design, 3D printing, and embedded systems.

The system recreates the BB8 robot from Star Wars using a spherical drive mechanism, wireless control, and a custom 3D printed internal structure.

The project placed 2nd overall in the competition.

The robot is controlled wirelessly through a Bluetooth module connected to an Arduino, allowing real-time user input from a mobile device. A differential drive system inside the sphere enables the robot to move forward, backward, and turn.

![Internal Structure](robot internals.JPG)

System Overview

The robot integrates electrical, mechanical, and software subsystems into a single design:

- Arduino Mega controls all system logic  
- L298N motor driver powers two TT motors  
- Bluetooth module enables wireless communication  
- Battery pack provides portable power  
- Custom 3D printed structure houses and stabilizes components inside the spherical shell  

The internal structure was designed to maintain stability and proper weight distribution while allowing the robot to move effectively within the ball.

Key Features

- Fully wireless Bluetooth control
- Differential drive system inside spherical enclosure
- Custom 3D printed internal support structure
- Real-time command processing
- Integration of mechanical, electrical, and software systems

Command Interface

The robot responds to simple character-based commands:

- U: Move forward  
- D: Move backward  
- L: Turn left  
- R: Turn right  
- S: Stop  

Code Highlights

### Centralized Command Handling

All movement commands are processed through a single function, simplifying system behavior and making the code easier to maintain.

```cpp
void handleCommand(char cmd) {
  switch (cmd) {
    case 'U': forward(); break;
    case 'D': back(); break;
    case 'L': left(); break;
    case 'R': right(); break;
    case 'S': Stop(); break;
    default:  Stop(); break;
  }
}
```

### Dual Communication Interface

The robot accepts commands from both the serial monitor and a Bluetooth module, allowing for easy debugging and wireless operation.

```cpp
if (Serial.available() > 0) { 
  command = Serial.read(); 
  handleCommand(command);
}

if (BTSerial.available() > 0) { 
  command = BTSerial.read(); 
  handleCommand(command);
}
```

### Differential Drive Control

Independent motor control enables forward motion and turning within the spherical enclosure.

```cpp
void left()
{
  analogWrite(motorSpeedPin, 60);
  digitalWrite(motorDirection1, HIGH);
  digitalWrite(motorDirection2, LOW);

  analogWrite(motor2SpeedPin, 60);
  digitalWrite(motor2Direction1, LOW);
  digitalWrite(motor2Direction2, HIGH);
}
```

Design Challenges

- Fitting all components within a confined spherical space  
- Maintaining stability and center of mass for consistent movement  
- Managing power requirements for high-torque motors  
- Implementing reliable Bluetooth communication  

An IMU sensor (GY-521) was initially planned for orientation tracking, but was not successfully integrated due to communication and software limitations.

Team Contribution

This project was completed as part of a newly formed team with varying levels of technical experience. I contributed to both the mechanical design and the development of the embedded control system.

I took a leading role in implementing the Bluetooth control system, motor control logic, and overall system integration, while also assisting teammates in understanding the development tools and system behavior.

Despite these challenges, the project successfully placed 2nd overall in the competition.

Results

The robot successfully demonstrated:

- Reliable wireless control  
- Consistent directional movement  
- Stable operation within the spherical design  

A demonstration of the system in operation can be seen here:  
https://youtube.com/shorts/6Pg4Oi1Q9J0

Future Improvements

- Integrate IMU feedback for orientation tracking  
- Improve motion smoothness with speed control or ramping  
- Develop a mechanism to stabilize and attach the BB8 head  
- Refine internal structure for better balance and efficiency  
