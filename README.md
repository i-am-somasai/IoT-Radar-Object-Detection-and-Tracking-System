🔫 Ultrasonic Radar-Guided Turret with ESP-NOW Communication
This project simulates a radar-guided turret system that detects and tracks nearby objects using an ultrasonic sensor, servo motors, and LED indicators. The system wirelessly transmits live angle and distance data to a remote ESP32 using ESP-NOW protocol, enabling remote monitoring or control.

🚀 Features
📡 Radar Scanning: A servo sweeps between 15° and 165°, mimicking radar behavior to detect objects.

🔍 Ultrasonic Distance Detection: Uses an HC-SR04 ultrasonic sensor to calculate the distance of objects in front of the radar.

🎯 Gun Tracking: A second servo ("gun servo") aims directly at objects detected within 10 cm.

🟢🔴 LED Indicators:

Red LED turns ON when an object is detected within danger range.

Green LED indicates a clear path.

📶 ESP-NOW Communication: Real-time transmission of angle and distance data from Arduino to ESP32 (receiver).

🖥️ Serial Monitoring: The receiver prints angle and distance data, ideal for debugging or further analysis.

🛠️ Hardware Required
Component	Quantity
Ultrasonic Sensor (HC-SR04)	1
Servo Motors (e.g., SG90)	2
ESP32 Development Board	1 (Receiver)
Arduino Board (Uno/Nano)	1 (Transmitter)
LEDs (Red & Green)	1 each
Resistors (220Ω)	2
Jumper Wires & Breadboard	as needed
USB Cables	2

🧠 How It Works
The Arduino continuously sweeps a servo from 15° to 165° and measures the distance at each step using the ultrasonic sensor.

If an object is detected closer than 10 cm:

The gun servo rotates to aim at the object.

The red LED turns ON (alert).

If no nearby object is detected:

The gun resets to center.

The green LED turns ON.

At every angle, the angle and distance data are wirelessly transmitted to an ESP32 using ESP-NOW.

The ESP32 receiver displays the incoming data via the serial monitor.
🔧 Setup Instructions
Arduino (Transmitter)
Upload RADARSenderCode.ino to your Arduino.

Connect:

HC-SR04 to digital pins 2 and 9.

Radar Servo to pin 12.

Gun Servo to pin 11.

Red/Green LEDs to pins 6 and 7.

ESP32 (Receiver)
Upload RADARReceiverCode.ino to the ESP32.

Get the MAC address of the ESP32 and hard-code it in the transmitter code (if needed).

Open the Serial Monitor at 115200 baud to view incoming angle-distance data.

📡 ESP-NOW Pairing Tip
Make sure the MAC address of the receiver ESP32 is correctly defined in the transmitter. Use WiFi.macAddress() to obtain it.

🧭 Applications
Object detection and tracking systems

Prototyping security turrets

Radar simulation projects

IoT distance monitoring

Robotics with autonomous threat detection
