# IoT Gas Detection System

This project is an IoT-based gas detection system that uses various MQ sensors (MQ2, MQ4, MQ6, MQ7, MQ9, MQ135) along with a DHT11 sensor for real-time environmental monitoring. It is designed to detect and measure gas concentrations and environmental conditions like temperature and humidity. The data is displayed on the serial monitor and can be used for safety monitoring or further integration with an alert system.

## Features

- Monitors air quality using MQ sensors for gases like smoke, methane, LPG, CO, ammonia, and CO2.
- Displays temperature and humidity readings using the DHT11 sensor.
- Warns when gas concentrations exceed predefined thresholds.

## Sensors Used

- **MQ2**: Detects smoke, LPG, methane, alcohol, and carbon monoxide.
- **MQ4**: Primarily detects methane and natural gas.
- **MQ6**: Detects LPG, butane, and propane.
- **MQ7**: Measures carbon monoxide (CO) concentrations.
- **MQ9**: Detects carbon monoxide, methane, LPG, and CO.
- **MQ135**: Measures air quality, including ammonia, benzene, alcohol, smoke, and CO2.
- **DHT11**: Measures temperature and humidity.

## Thresholds

- **MQ2**: 400
- **MQ4**: 500
- **MQ6**: 1000
- **MQ7**: 200
- **MQ9**: 150
- **MQ135**: 400

The sensor readings are compared against these threshold values to detect high levels of gases and trigger warnings.

## Installation

1. Clone this repository:
   ```bash
   git clone https://github.com/yourusername/IoT-Gas-Detection-System.git


   
![Uploading circuit_image (2).png…]()
