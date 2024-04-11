#include <LiquidCrystal.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

const int rightMic = A3;
const int leftMic = A2;
int rightMicState = 0;
int leftMicState = 0;

int buzzerPin = 9;
int flashPin = 3;
int flashDelay = 165;

int loudnessThreshold = 300;

LiquidCrystal_I2C lcd(0x27,16,2);

unsigned long lastMessageChange = millis();
long messageInterval = 10000;
String ranMessages[] = {"Disagreement doesn't mean hatred"};

void setup(){
  pinMode(rightMic, INPUT);
  pinMode(leftMic, INPUT);
  pinMode(buzzerPin, OUTPUT);
  pinMode(flashPin, OUTPUT);
  Serial.begin(9600);
  lcd.init();
}

void loop(){
  rightMicState = analogRead(rightMic);
  leftMicState = analogRead(leftMic);
  Serial.print("Right: ");
  Serial.println(rightMicState);
  
  Serial.print("Left: ");
  Serial.println(leftMicState);
  delay(100);
  digitalWrite(buzzerPin, HIGH);

  if (rightMicState > loudnessThreshold || leftMicState > loudnessThreshold){
    lcd.clear();
    lcd.backlight();
    lcd.setCursor(0, 0);
    lcd.print("indoor voices");
    lcd.setCursor(0,1);
    lcd.print("please");
    flashAndBuzz();
    delay(200);
    }

}

void flashAndBuzz(){
  tone(buzzerPin, 1000);

  digitalWrite(flashPin, HIGH);
  delay(flashDelay);
  digitalWrite(flashPin, LOW);
  delay(flashDelay);
   digitalWrite(flashPin, HIGH);
  delay(flashDelay);
  digitalWrite(flashPin, LOW);
  delay(flashDelay);
   digitalWrite(flashPin, HIGH);
  delay(flashDelay);
  digitalWrite(flashPin, LOW);
  digitalWrite(buzzerPin, LOW);

  noTone(buzzerPin);
}