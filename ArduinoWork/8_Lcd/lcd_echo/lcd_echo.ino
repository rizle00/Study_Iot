#include <Wire.h>
#include <LiquidCrystal_I2C.h>
int echoPin = 7, trigPin =6;

// 주소는 LCD 모듈에 따라 다를 수 있습니다.
LiquidCrystal_I2C lcd(0x27, 16, 2);  // 주소, 열 수, 행 수

void setup() {
  // lcd.begin(16,2);  // LCD 초기화
  Serial.begin(9600);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  lcd.init();  
  lcd.backlight();  // 백라이트 활성화
 lcd.setCursor(0,0);
  lcd.print("hello, world!!");
  // lcd.setCursor(0,1);
  // lcd.print("Ywrobot Arduino!");
}

void loop() {
  
print(echo());
}

float echo(){
  if(Serial.available()){
    if(Serial.read() == 'y'){
      delay(500);
      digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  long duration = pulseIn(echoPin, HIGH);
  float distance = duration * 0.034 / 2;
  return distance;
  }
  }
}

void print(float distance){

    // lcd.clear();
    // delay(200);
   lcd.setCursor(0,0);
  
  lcd.print("distance: ");
  lcd.setCursor(0,1);
  Serial.println(distance);
  lcd.print(distance);
  lcd.print(" cm");
   lcd.setCursor(14,1);
   lcd.print(millis()/1000);
   delay(500);
  
}