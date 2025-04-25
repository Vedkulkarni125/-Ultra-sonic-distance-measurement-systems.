#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <NewPing.h>

// Set the pins for the ultrasonic sensor
#define TRIGGER_PIN 9
#define ECHO_PIN 10
#define MAX_DISTANCE 200 // Maximum distance to measure in centimeters

// Initialize the LCD
LiquidCrystal_I2C lcd(0x27, 16, 2);  // Change this to the correct I2C address if needed

// Initialize the ultrasonic sensor
NewPing sonar(TRIGGER_PIN, ECHO_PIN, MAX_DISTANCE);

void setup() {
  lcd.init();  // Use init() instead of begin()
  lcd.backlight();
  lcd.setCursor(0, 0);
  lcd.print("Distance:");
}

void loop() {
  // Measure distance in centimeters
  unsigned int distance = sonar.ping_cm();

  // Clear the previous distance value
  lcd.setCursor(0, 1);
  lcd.print("                "); // Clear the line

  // Display the measured distance
  lcd.setCursor(0, 1);
  if (distance > 0) {
    lcd.print(distance);
    lcd.print(" cm");
    delay(1000);
  } else {
    lcd.print("Out of range");
  }

  delay(10); // Wait for 1 second before the next measurement
}
