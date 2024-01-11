// 라이브러리 가져오기
#include <Servo.h>
// 객체 생성
Servo servo;
int echoPin = 7, trigPin =6;
void setup() {
  // put your setup code here, to run once:
  // 모터 포트 지정
  servo.attach(13);
  // 모터를 0도로 초기화
  servo.write(0);
   Serial.begin(9600);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);


}

void loop() {
  // for(int i =0; i<180; i++){
  //   servo.write(i);
  //   delay(10);
  // }
  // for(int i =179; i>0; i--){
  //   servo.write(i);
  //   delay(10);
  // }
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  // Echo 핀으로부터 초음파 수신 시간 측정
  
  long duration = pulseIn(echoPin, HIGH);

  // 거리 계산 (음속: 340m/s)
  float distance = duration * 0.034 / 2;
  // *0.034 = /29.4
  // float distance = duration /29.4 / 2;
  
if(distance<20 && distance>0){
  // 거리를 시리얼 모니터에 출력
  
  Serial.print("거리: ");
  Serial.print(distance);
  Serial.println(" cm");
  servo.write(90);
  delay(3000); // 1초 대기
  } else{
     Serial.print("거리: ");
  Serial.print(distance);
  Serial.println(" cm");
  servo.write(0);
  delay(3000);
  }

}
