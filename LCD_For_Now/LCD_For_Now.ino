#include <LiquidCrystal.h>

#include <Wire.h>
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27,16,2);

String screenSaver[] = []


void setup() {
  // put your setup code here, to run once:
  lcd.init();
}

void loop() {
  // put your main code here, to run repeatedly:
  lcd.backlight();
  lcd.setCursor(0, 0);
  lcd.print("indoor voices, it's just a debate!");
  delay(200);
}

/*
lcd.backlight();
  lcd.setCursor(0, 0);
  lcd.print("");
  delay(200);


  lcd.backlight();
  lcd.setCursor(0, 0);
  lcd.print("remember to shake your opponent's hand!");
  delay(200);


  lcd.backlight();
  lcd.setCursor(0, 0);
  lcd.print("Woahhh language!!1!");
  delay(200);


  lcd.backlight();
  lcd.setCursor(0, 0);
  lcd.print("remember that friends can disagree :)");
  delay(200);
*/
