int ledY = 3, ledG = 13; // PWM을 사용할 디지털 핀 번호
int currentLed = 1;
int brightness = 0; // LED의 초기 밝기 값
int fadeAmount = 5;

void setup() {
  // put your setup code here, to run once:
  pinMode(ledY,OUTPUT);
  pinMode(ledG, OUTPUT);

}

void loop() {
  // put your main code here, to run repeatedly:
// analogWrite(ledY, brightness);

//   brightness += fadeAmount;
//   if (brightness == 255) {
//     fadeAmount = -fadeAmount;
    
//   } else if(brightness == 0){
//      fadeAmount = -fadeAmount;
    
//   } delay(30);

// analogWrite(ledY, brightness); // 첫 번째 LED를 현재 밝기 값으로 조절
//   analogWrite(ledG, 255 - brightness); // 두 번째 LED를 반대로 조절

//   brightness = brightness + fadeAmount; // 밝기 값을 증가시킴

//   // 밝기 값이 0 또는 255에 도달하면 fadeAmount의 부호를 바꿔 어두워지게 함
//   if (brightness == 0 || brightness == 255) {
//     fadeAmount = -fadeAmount;
//   }

//   delay(30); // 잠시 대기

  // ananlogWrite(ledG, 100);
  // delay(100);
  // ananlogWrite(ledG, 170);
  // delay(100);
  // ananlogWrite(ledG, 255);
  // delay(100);
  // ananlogWrite(ledG, 0);
  // delay(100);

   if (currentLed == 1) {
    analogWrite(ledY, 255 - brightness); // 첫 번째 LED를 반대로 조절
    analogWrite(ledG, brightness); // 두 번째 LED를 현재 밝기 값으로 조절
  } else {
    analogWrite(ledY, brightness); // 첫 번째 LED를 현재 밝기 값으로 조절
    analogWrite(ledG, 255 - brightness); // 두 번째 LED를 반대로 조절
  }

   brightness = brightness + fadeAmount; // 밝기 값을 증가시킴

  // 밝기 값이 0 또는 255에 도달하면 fadeAmount의 부호를 바꿔 어두워지게 함
  if (brightness == 0 || brightness == 255) {
    fadeAmount = -fadeAmount;
    currentLed = (currentLed == 1) ? 2 : 1; // 다른 LED로 전환
  }

  delay(30); // 잠시 대기
}
