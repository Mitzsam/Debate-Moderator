#include <LiquidCrystal.h>

#include <Wire.h>
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27,16,2);




void setup() {
  // put your setup code here, to run once:
  lcd.init();
  
 
}

void loop() {
  // put your main code here, to run repeatedly:
  lcd.backlight();
  lcd.setCursor(0, 0);
  lcd.print("remember to shake your opponent's hand!");
  delay(200);
}
