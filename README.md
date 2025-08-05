# Soil Moisture Based Auto Irrigation System with LCD

This Arduino project automatically irrigates plants based on soil moisture readings and displays system status on an I2C LCD.

## Features

- Real-time soil moisture monitoring using analog capacitance sensor
- Pump control using relay (ON when dry, OFF when wet)
- Live display on 16x2 LCD (I2C)
- Calibration values for wet and dry soil adjustable in code

## Hardware Used

- Arduino Uno/Nano
- Capacitance soil moisture sensor (analog)
- 5V relay module
- Submersible Water pump
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

## How to Use

1. Connect the soil moisture sensor output to analog pin A0 on the Arduino.
2. Connect the relay module input to digital pin D7.
3. Connect the 16x2 I2C LCD display to the SDA (A4) and SCL (A5) pins.
4. Upload the Arduino sketch to your board.
5. Power the Arduino and pump setup.
6. Monitor the LCD screen for soil moisture percentage and pump status.
7. Adjust the WET and DRY calibration values in the code as needed for your soil.

## What I learned

- How to read analog sensor data and convert it to meaningful percentages.
- Integrate a real-time clock (RTC) to water only during specific times of day.
- Add a buzzer or notification system to alert when watering occurs or needs attention.
- Expand to multiple sensors for zone-based irrigation control.
