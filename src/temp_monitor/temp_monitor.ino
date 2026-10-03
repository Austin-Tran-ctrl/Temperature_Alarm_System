#include <Wire.h>
#include <LiquidCrystal_I2C.h>

const int tempPin = A0;      
const int greenLED = 2;      
const int redLED = 3;       
const int buzzer = 5;      

const float TEMP_LOW = 80.0; //range of "safe" temperatures
const float TEMP_HIGH = 90.0; 

LiquidCrystal_I2C lcd(0x27, 16, 2);

void setup() {
  pinMode(greenLED, OUTPUT);
  pinMode(redLED, OUTPUT);
  pinMode(buzzer, OUTPUT);

  digitalWrite(greenLED, HIGH);  // green LED on at start

  Serial.begin(9600);
  lcd.begin(16, 2);
  lcd.backlight();

  lcd.setCursor(0, 0);
  lcd.print("Temp Monitor");
  delay(2000);
  lcd.clear();
}

void loop() {

  int sensorVal = analogRead(tempPin);
  float voltage = sensorVal * (5.0 / 1023.0);
  float tempC = (voltage - 0.5) * 100.0;
  float tempF = tempC * 9.0 / 5.0 + 32.0;

  Serial.print("Temp: "); //display on LCD screen
  Serial.print(tempC);
  Serial.print(" C / ");
  Serial.print(tempF);
  Serial.println(" F");

  lcd.setCursor(0, 0);
  lcd.print("Celsius: ");
  lcd.print(tempC, 1);
  lcd.print((char)223);
  lcd.print("C   ");  

  lcd.setCursor(0, 1);
  lcd.print("Fahrenheit: ");
  lcd.print(tempF, 1);
  lcd.print((char)223);
  lcd.print("F  ");

  if (tempF < TEMP_LOW || tempF > TEMP_HIGH) { //if temp is outside specified range then turn on red LED and buzzer 
    for (int i = 0; i < 2; i++) {
      digitalWrite(redLED, HIGH);
      tone(buzzer, 2000);
      delay(200);

      digitalWrite(redLED, LOW);
      noTone(buzzer);
      delay(200);
    }
  } else {
    digitalWrite(redLED, LOW);
    noTone(buzzer);
  }

  delay(500); 
}
