#include <Wire.h>
#include <LiquidCrystal_I2C.h>

// LCD setup (I2C address 0x27, 16 columns, 2 rows)
LiquidCrystal_I2C lcd(0x27, 16, 2);

// Pin definitions
#define sensorPin A0
#define relayPin 7

// Moisture calibration values (adjust to your soil)
#define WET 210    // Raw sensor value when soil is fully wet
#define DRY 510    // Raw sensor value when soil is dry

void setup() {
  Serial.begin(9600);

  // LCD initialization
  lcd.init();
  lcd.backlight();
  lcd.setCursor(0, 0);
  lcd.print("Auto Irrigation");

  // Relay setup
  pinMode(relayPin, OUTPUT);
  digitalWrite(relayPin, LOW); // Ensure pump is OFF initially

  delay(2000); // Read welcome message
  lcd.clear();
}

void loop() {
  int moisture = analogRead(sensorPin); // Read raw moisture value

  // Map raw value to % and constrain to 0-100
  int moisturePercent = map(moisture, WET, DRY, 100, 0);
  moisturePercent = constrain(moisturePercent, 0, 100);

  // Print to Serial Monitor for debugging
  Serial.print("Moisture: ");
  Serial.print(moisturePercent);
  Serial.println("%");

  // Display on LCD
  lcd.setCursor(0, 0);
  lcd.print("Moist: ");
  lcd.print(moisturePercent);
  lcd.print("%   "); // Clears leftovers

  // Pump control logic
  if (moisturePercent < 30) { // Soil dry, turn pump ON
    digitalWrite(relayPin, HIGH);
    lcd.setCursor(0, 1);
    lcd.print("Pump: ON         ");
  } else { // Soil moist, turn pump OFF
    digitalWrite(relayPin, LOW);
    lcd.setCursor(0, 1);
    lcd.print("Pump: OFF        ");
  }

  delay(1000); // Update every 1 second
}
