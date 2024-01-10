
int echoPin = 7, trigPin =6, piezoPin = 13;
#define C5 523
#define D5 587
#define E5 659

void setup() {
  // put your setup code here, to run once:
   Serial.begin(9600);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(piezoPin, OUTPUT);

}

void loop() {
  // put your main code here, to run repeatedly:
   // 초음파 송신 시작
   while(Serial.available()){
    if(Serial.read() == 'y'){

  
   
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
  
if(distance<100 && distance>50){
  // 거리를 시리얼 모니터에 출력
  tone(piezoPin, C5, 200 );
  Serial.print("거리: ");
  Serial.print(distance);
  Serial.println(" cm");

  delay(1000); // 1초 대기
  } else if(distance<51 && distance>25){
  // 거리를 시리얼 모니터에 출력
  tone(piezoPin, D5, 200 );
  Serial.print("거리: ");
  Serial.print(distance);
  Serial.println(" cm");

  delay(500); // 1초 대기
  } else if(distance<26){
  // 거리를 시리얼 모니터에 출력
  tone(piezoPin, E5, 200 );
  Serial.print("거리: ");
  Serial.print(distance);
  Serial.println(" cm");

  delay(200); // 1초 대기
  }
    }
  }

}
