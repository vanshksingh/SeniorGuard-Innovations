# SeniorGuard-Innovations
Turing Sapiens Hackathon



# Elder's Friend - An Elderly Care System
![Uploading Screenshot 2023-11-07 at 5.34.27 AM.png…]()

![Uploading Screenshot 2023-11-07 at 5.34.21 AM.png…]()


## Overview

**Elder's Friend** is an innovative and compassionate system designed to assist in the care of the elderly. It incorporates various sensors and alert mechanisms to ensure the well-being of senior citizens. This README provides an in-depth understanding of the code, its components, and how to use them effectively.

**Author: Your Name**

## Table of Contents

- [Getting Started](#getting-started)
- [Features](#features)
- [How to Use](#how-to-use)
- [Code Logic](#code-logic)
- [Sensors and Components](#sensors-and-components)
- [Customization](#customization)
- [Contributing](#contributing)
- [License](#license)

## Getting Started

To set up **Elder's Friend**, you need the following:

1. Hardware components (e.g., moisture sensor, touch sensor, PIR sensor, buzzer, LCD display, push button, and servo motor).
2. An Arduino-compatible board (e.g., Arduino UNO).
3. The [Arduino IDE](https://www.arduino.cc/en/software) installed on your computer.
4. Appropriate connections for sensors and actuators.

## Features

**Elder's Friend** provides the following key features:

1. Moisture Sensor: Monitors moisture levels to detect if the user needs assistance.
2. Touch Sensor: Allows the user to call for help by touching the sensor.
3. PIR (Passive Infrared) Sensor: Detects the presence of a person and deactivates the buzzer if a person is detected.
4. Emergency Button: An easily accessible button to alert emergency services.
5. Buzzer: Sounds alerts when help is needed or in emergency situations.
6. LCD Display: Shows helpful information, alerts, and a timer for assistance calls.

## How to Use

1. Connect the required sensors and actuators to your Arduino board as specified in your project documentation.
2. Open the Arduino IDE and upload the provided code to your board.

For specific hardware connections and setup instructions, refer to the hardware documentation for your project.

## Code Logic

The code is organized to monitor various sensors and provide timely alerts. Here's an overview of the code logic:

1. Initialization of sensors, actuators, and the LCD display.
2. Monitoring moisture levels, touch sensor, and PIR sensor.
3. Handling emergency button presses to alert emergency services.
4. Alerting and displaying information on the LCD screen.
5. Providing alerts and assistance when needed.

## Sensors and Components

1. **Moisture Sensor**: Monitors moisture levels, and if they drop below a certain threshold, the system alerts that assistance is needed.

2. **Touch Sensor**: Allows the user to call for help by touching the sensor. The system activates an alert and displays a "Help Called" message.

3. **PIR Sensor**: Detects the presence of a person. If a person is detected, it deactivates the buzzer to avoid unnecessary alerts.

4. **Emergency Button**: An easily accessible button to alert emergency services. When pressed, the system displays an "Alerting emergency services" message and sounds the buzzer.

5. **Buzzer**: The buzzer sounds alerts when help is needed or in emergency situations. It's controlled based on sensor inputs.

6. **LCD Display**: Shows helpful information, alerts, and a timer for assistance calls. It also displays a "Welcome" message when the system starts.

## Customization

You can customize the system by:

- Adjusting sensor thresholds to trigger alerts at different levels.
- Modifying LCD display messages and designs.
- Enhancing the alert mechanism with additional actuators or communication channels.

Customization should be aligned with the specific needs and preferences of the elderly person the system is designed for.

## Contributing

Contributions to this project are welcome. If you have ideas for improvements or new features, please follow these steps:

1. Fork the repository.
2. Create a new branch for your feature or bug fix.
3. Make your changes and test them thoroughly.
4. Submit a pull request with a clear description of your changes.

## License

This project is licensed under the [MIT License](LICENSE). Feel free to use and modify the code for your projects.

---

**Elder's Friend** is a caring and responsive system designed to enhance the well-being of senior citizens. If you have any questions or encounter issues, please don't hesitate to open an issue or reach out to the project's author. Your contributions and thoughtful customizations can make a real difference in the lives of the elderly.
