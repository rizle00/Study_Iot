#include <Wire.h>
#include <LiquidCrystal_I2C.h>

// 주소는 LCD 모듈에 따라 다를 수 있습니다.
LiquidCrystal_I2C lcd(0x27, 16, 2);  // 주소, 열 수, 행 수

void setup() {
  // lcd.begin(16,2);  // LCD 초기화
  lcd.init();  
  lcd.backlight();  // 백라이트 활성화
 lcd.setCursor(0,0);
  lcd.print("안녕");
  // lcd.setCursor(0,1);
  // lcd.print("Ywrobot Arduino!");
}

void loop() {
  for(int i =0; i<13; i++){
    lcd.scrollDisplayLeft();
    delay(200);
  }
  for(int i =0; i<13+16; i++){
    lcd.scrollDisplayRight();
    delay(100);
  }
  for(int i =0; i<16; i++){
    lcd.scrollDisplayLeft();
    delay(200);
  }
   for(int i =0; i<10; i++){
    lcd.clear();
    delay(200);
   lcd.setCursor(0,0);
  lcd.print("Hello, world!");
   lcd.setCursor(0,1);
   lcd.print(millis()/1000);
   delay(500);
  }

}