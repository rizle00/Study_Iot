

// 실행 시 한번 만 실행
void setup() {
  // put your setup code here, to run once:
  // 각 포트에 대한 모드를 지정
   pinMode(13, OUTPUT);
  
}


// 반복 실행
void loop() {
  // put your main code here, to run repeatedly:
  // LED 를 켬
  

  digitalWrite(13, 1);
  // 1초 간 딜레이 , 불 켜질 시간, 처리하는 속도가 매무 빠르기 때문에..
  delay(1000);  
  digitalWrite(13, 0);
  delay(1000);

}
