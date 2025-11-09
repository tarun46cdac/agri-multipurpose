# AgriBot - Multi-Purpose Farming Robot

AgriBot is a multi-purpose agricultural robot built using an ESP32 microcontroller. 
It performs seed sowing, pesticide spraying, irrigation, and grass cutting, all controlled wirelessly via the Blynk IoT platform.

## Features
- Wireless control using Blynk IoT
- Forward, backward, left and right movement
- Seed sowing mechanism
- Water/pesticide spraying system
- Grass cutting motor
- Relay-based actuation for multiple motors

## Hardware Used
- ESP32 Development Board
- Relay modules (7-channel)
- 12V DC geared motors (2 for movement)
- DC motor for seed sowing
- DC pump motor for spraying
- Grass cutter motor (775-type)
- 6V batteries (in series)
- Solar panel (optional charging)
- Boost converter
- Motor driver components and chassis

## ESP32 Pin Connections
| Function         | Relay | ESP32 Pin |
|------------------|-------|-----------|
| Forward Left     | r1    | 15        |
| Forward Right    | r2    | 2         |
| Backward Left    | r3    | 4         |
| Backward Right   | r4    | 5         |
| Seed Motor       | r5    | 18        |
| Pump Motor       | r6    | 19        |
| Cutter Motor     | r7    | 21        |

## How to Run
1. Open firmware/agribot_firmware.ino in Arduino IDE.
2. Install ESP32 board support in Arduino IDE.
3. Install Blynk library.
4. Create secrets.h file inside firmware/ and add your WiFi and Blynk credentials.
5. Select ESP32 Dev Module as board.
6. Upload the code.
7. Open Blynk app and control the robot.

## Photos
![Robot Front View](docs/README-images/front-view.jpg)
![Robot side View](docs/README-images/side-view.jpg)
![Blynk UI Screenshot](docs/README-images/blynk.jpg)
![circuit](docs/README-images/circuit.jpg)
![Block diagram](docs/README-images/block-diagram.jpg)
