# Soil Moisture Based Auto Irrigation System with LCD

This Arduino project automatically irrigates plants based on soil moisture readings and displays system status on an I2C LCD.

## Features

- Real-time soil moisture monitoring using analog sensor
- Pump control using relay (ON when dry, OFF when wet)
- Live display on 16x2 LCD (I2C)
- Calibration values for wet and dry soil adjustable in code

## Hardware Used

- Arduino Uno/Nano
- Soil moisture sensor (analog)
- 5V relay module
- Water pump
- 16x2 I2C LCD display
- Breadboard + jumper wires

## Pin Configuration

| Component           | Arduino Pin |
|--------------------|-------------|
| Soil Sensor Signal | A0          |
| Relay IN           | D7          |
| LCD SDA            | A4          |
| LCD SCL            | A5          |

## Calibration Tips

Adjust `#define WET` and `#define DRY` based on your own soil type and readings when fully wet and dry.
