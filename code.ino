#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <ESP32Servo.h>

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
#define OLED_RESET    -1
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

Servo myServo;
const int servoPin = 13;

void setup() {
  Serial.begin(115200);

  // Initialize OLED display (I2C address 0x3C)
  if(!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {
    Serial.println(F("SSD1306 allocation failed"));
    for(;;);
  }
  
  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(SSD1306_WHITE);
  
  // Initialize Servo
  myServo.attach(servoPin);
}

void loop() {
  // Sweep servo from 0 to 180 degrees and update OLED
  for (int pos = 0; pos <= 180; pos += 10) {
    myServo.write(pos);
    updateDisplay(pos);
    delay(100);
  }

  // Sweep servo from 180 to 0 degrees and update OLED
  for (int pos = 180; pos >= 0; pos -= 10) {
    myServo.write(pos);
    updateDisplay(pos);
    delay(100);
  }
}

void updateDisplay(int angle) {
  display.clearDisplay();
  
  // Title
  display.setCursor(0, 0);
  display.print(F("ESP32 Servo Control"));
  
  // Divider line
  display.drawFastHLine(0, 12, SCREEN_WIDTH, SSD1306_WHITE);
  
  // Servo Angle Output
  display.setCursor(0, 25);
  display.setTextSize(2);
  display.print(F("Angle: "));
  display.print(angle);
  display.print((char)247); // Degree symbol
  
  display.setTextSize(1);
  display.setCursor(0, 52);
  display.print(F("CodetoCircut Build"));
  
  display.display();
}
