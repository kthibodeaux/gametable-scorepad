#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);

void setup() {
  Serial.begin(115200);

  Wire.begin();
  lcd.init();
  lcd.backlight();

  lcd.setCursor(0, 0);
  lcd.print("  Hello World!  ");
  lcd.setCursor(0, 1);
  lcd.print("Count: ");

  Serial.println("LCD init done");
}

void loop() {
  static unsigned long count = 0;

  lcd.setCursor(7, 1);
  lcd.print(count);
  lcd.print("   ");

  Serial.print("Count: ");
  Serial.println(count);

  count++;
  delay(1000);
}
