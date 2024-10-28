#include <Servo.h>
#include <SoftwareSerial.h>
#define IR_SENSOR_PIN 7
#define SOIL_MOISTURE_PIN A0
#define SERVO_PIN 9
#define BT_TX_PIN 10
#define BT_RX_PIN 11
Servo servoMotor;
SoftwareSerial BT(BT_RX_PIN, BT_TX_PIN);
int wetWasteCount = 0;
int dryWasteCount = 0;
void setup() {
pinMode(IR_SENSOR_PIN, INPUT);
pinMode(SOIL_MOISTURE_PIN, INPUT);
servoMotor.attach(SERVO_PIN);
servoMotor.write(90); // Set initial position to neutral (90 degrees)
Serial.begin(9600);
BT.begin(9600); // Initialize Bluetooth serial communication
}

void loop() {
int irSensorValue = digitalRead(IR_SENSOR_PIN);
// Check if object is detected
if (irSensorValue == LOW) {
delay(2000); // Wait for 2 seconds to stabilize
int soilMoistureValue = analogRead(SOIL_MOISTURE_PIN); // Read soil moisture
Serial.print("Moisture Reading: ");
Serial.println(soilMoistureValue);
if (soilMoistureValue < 800) { // Wet
rotateServoLeft(); // Rotate towards wet
Serial.println("Item is Wet");
wetWasteCount++; // Increment wet waste count
} else { // Dry
rotateServoRight(); // Rotate towards dry
Serial.println("Item is Dry");
dryWasteCount++; // Increment dry waste count
}

// Transmit waste counts over Bluetooth
BT.print("Wet: ");
BT.print(wetWasteCount);
BT.print(", Dry: ");
BT.println(dryWasteCount);
// Display waste counts in Serial Monitor
Serial.print("Wet Waste Count: ");
Serial.print(wetWasteCount);
Serial.print(", Dry Waste Count: ");
Serial.println(dryWasteCount);
}
}
void rotateServoLeft() {
for (int angle = 90; angle <= 180; angle++) {
servoMotor.write(angle); // Rotate left (towards wet)
delay(20); // Adjust delay for slower speed
}
delay(1000); // Wait for return to complete
servoMotor.write(90); // Return to initial position (neutral)
delay(1000); // Wait for return to complete
}
void rotateServoRight() {
// Rotate right (towards dry)
for (int angle = 90; angle >= 0; angle--) {
servoMotor.write(angle);
delay(20); // Adjust delay for slower speed, same as the down movement
}
// Return slowly to neutral position
for (int angle = 0; angle <= 90; angle++) {
servoMotor.write(angle);
delay(20); // Adjust delay for slower speed, same as the down movement
}
delay(1000); // Wait for return to complete
}