#include <Wire.h>
#include <LiquidCrystal.h>
#include <Servo.h>

const int buzzerPin = 2;           // Buzzer Pin for alerts
const int moisturePin = A15;       // Moisture Sensor Pin
const int touchSensorPin = 3;       // Touch Sensor Pin
const int emergencyButtonPin = 5;   // Push Button Pin for emergency
int Contrast = 60;
const int rs = A3, en = A5, d4 = A9, d5 = A10, d6 = A11, d7 = A12;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

Servo myservo;
const int servoPin = 4;             // Servo Pin for action
const int alertThreshold = 10;      // Set the alert threshold in seconds (default: 10 seconds)
const int pirSensorPin = 6;         // PIR Sensor Pin

unsigned long previousTime = 0;
bool isBuzzerOn = false;
bool isHelpCalled = false;
unsigned long noPersonDetectedTime = 0;
bool isPersonDetected = true;

void setup() {
  Serial.begin(9600);
  Wire.begin();

  analogWrite(9, Contrast);
  pinMode(A14, OUTPUT);
  pinMode(A13, OUTPUT);
  pinMode(A4, OUTPUT);
  pinMode(A0, OUTPUT);
  pinMode(A2, OUTPUT);
  pinMode(A1, OUTPUT);

  digitalWrite(A14, LOW);
  digitalWrite(A13, HIGH);
  digitalWrite(A4, LOW);
  digitalWrite(A0, LOW);
  digitalWrite(A2, LOW);
  digitalWrite(A1, HIGH);

  pinMode(buzzerPin, OUTPUT);
  pinMode(moisturePin, INPUT);
  pinMode(touchSensorPin, INPUT);
  pinMode(emergencyButtonPin, INPUT_PULLUP); // Set the push button as an input with a pull-up resistor
  pinMode(pirSensorPin, INPUT); // Set PIR sensor as input

  myservo.attach(servoPin); // Attach the servo

  Serial.println("Starting Up Elder's Friend by SeniorGuard Innovation");
  lcd.begin(16, 2);

  // Display the "starting up" animation
  displayBootAnimation();

  // Display the welcome message
  displayWelcomeMessage();
}

void loop() {
  int moistureValue = analogRead(moisturePin);

  // Calculate elapsed time
  unsigned long currentTime = millis();
  unsigned long elapsedTime = (currentTime - previousTime) / 1000; // Convert to seconds

  // Check if the push button for emergency is pressed
  if (digitalRead(emergencyButtonPin) == LOW) {
    // If the button is pressed, alert emergency services
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Alerting emergency");
    lcd.setCursor(0, 1);
    lcd.print("services");
    
    digitalWrite(buzzerPin, HIGH);
    delay(2000); // Beep the buzzer for 2 seconds

    // Clear the LCD and turn off the buzzer
    lcd.clear();
    digitalWrite(buzzerPin, LOW);
  }

  // Check if the touch sensor is touched
  if (digitalRead(touchSensorPin) == HIGH) {
    if (!isBuzzerOn) {
      // If touched and not previously touched, activate the buzzer and display "Help Called"
      digitalWrite(buzzerPin, HIGH);
      if (!isHelpCalled) {
        lcd.clear();
        lcd.setCursor(0, 0);
        lcd.print("Help Called");
        isHelpCalled = true;
      }
      isBuzzerOn = true;
    } else {
      // If touched again and the buzzer is already on, turn off the buzzer
      digitalWrite(buzzerPin, LOW);
      isBuzzerOn = false;

      // Clear the "Help Called" flag when touched again
      isHelpCalled = false;
    }
  }

  if (isHelpCalled) {
    lcd.setCursor(0, 0);
    lcd.print("Help Called");
  }

  if (!isHelpCalled) {
    // Show the time countdown only if "Help Called" is not being displayed
    lcd.clear();
    lcd.setCursor(0, 1);
    lcd.print("Time: ");
    lcd.print(elapsedTime);
  }

  // Check PIR sensor
  int pirSensorValue = digitalRead(pirSensorPin);
  Serial.println(pirSensorValue); // Print PIR sensor value to the serial monitor

  if (pirSensorValue == HIGH) {
    isPersonDetected = true;
    digitalWrite(buzzerPin, LOW);
  } 

  if (pirSensorValue == LOW) {
    isPersonDetected = false;
    digitalWrite(buzzerPin, HIGH);
    delay(10);
    if (isHelpCalled = false){
    
    digitalWrite(buzzerPin, LOW);
    }
  } 

  // Show "Assistance Needed" persistently if moisture is too low and no help has been called
  if (moistureValue < 1000) {
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Assistance Needed");
    lcd.setCursor(0, 1);
    lcd.print("Moisture High");
  }

  // Delay before the next reading
  delay(200); // Adjust as needed for the desired update frequency
}

void displayBootAnimation() {
  for (int i = 0; i < 2; i++) {
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Starting up");
    delay(500);

    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Starting up.");
    delay(500);

    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Starting up..");
    delay(500);

    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Starting up...");
    delay(500);
  }
}

void displayWelcomeMessage() {
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Senior Guard");
  lcd.setCursor(0, 1);
  lcd.print("Innovation");
  delay(1500);
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Presents:");
  lcd.setCursor(0, 1);
  lcd.print("Elder's Friend");
  delay(2500);
}