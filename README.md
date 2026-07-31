# ESP32 Servo & OLED Controller

A compact electronics project utilizing an ESP32 (30-pin DevKit V1) to control a servo motor while displaying live status information on an I2C 0.96-inch OLED screen.

## Components Used
* ESP32 DevKit V1 (30-pin)
* 0.96-inch I2C OLED Display (128x64)
* Standard Servo Motor
* Solderless Breadboard & Jumper Wires

## Wiring Guide

### OLED Display to ESP32
* **GND** -> GND
* **VCC** -> 3V3 (or 5V depending on module specs)
* **SCL** -> GPIO 22
* **SDA** -> GPIO 21

### Servo Motor to ESP32
* **Signal (Orange/Yellow)** -> GPIO 13
* **VCC (Red)** -> 5V (VIN)
* **GND (Brown/Black)** -> GND

## Code Setup
1. Open the Arduino IDE.
2. Ensure you have the **ESP32** board package installed.
3. Install the required libraries via the Library Manager:
   * `Adafruit_GFX`
   * `Adafruit_SSD1306`
   * `ESP32Servo`
4. Upload the sketch to your ESP32!
