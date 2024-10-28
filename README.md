# Smart Waste Management System

An intelligent waste segregation system that automatically differentiates between wet and dry waste, using an Arduino microcontroller with various sensors and components.

## Project Overview

This project aims to construct an automated waste bin that segregates waste into wet and dry categories to promote efficient recycling and waste management.

## Key Features

- **Automated Lid Mechanism**: Hands-free disposal with a lid that opens when waste is detected.
- **Dual Compartment System**: Separates wet and dry waste.
- **Bluetooth Connectivity**: Monitors waste levels and controls settings via a connected device.

## Components Used

- **Arduino Board**: Core processor that interprets sensor data and controls motor actions.
- **Moisture Sensor**: Detects moisture to identify wet waste.
- **IR Sensor**: Operates the lid for touch-free disposal.
- **Ultrasonic Sensor**: Measures waste level to determine when the bin is full.
- **Servo Motors**: Manages the opening and closing of lids for wet and dry compartments.
- **Bluetooth Module (HC-05)**: Enables wireless communication with external devices.

## Working Principle

The Smart Waste Management system utilizes the Arduino board to process data from multiple sensors. When waste is detected:
1. **IR Sensor** activates the bin lid.
2. **Moisture Sensor** determines if the waste is wet or dry.
3. **Servo Motors** direct the waste to the correct compartment.
4. **Bluetooth Module** transmits waste count and status to connected devices for real-time monitoring.

## Circuit Diagram

The circuit has been built using Autodesk Tinkercad, providing detailed wiring and component connections.

## Code

The code for this project is written in C++ for Arduino. The main code is located in the `smart_waste_management.ino` file. Key functionalities include:
- Moisture detection to distinguish between waste types
- Servo motor control for directing waste
- Bluetooth integration for data transmission

## Getting Started

### Prerequisites

- **Hardware**: Arduino board, moisture sensor, IR sensor, ultrasonic sensor, servo motor, Bluetooth module.
- **Software**: Arduino IDE.
