const int buttonPin = 12;  // 버튼이 연결된 핀 번호
const int ledPin1 = 13;
const int ledPin2 = 11;        // LED가 연결된 핀 번호
const int resPin = A0;
#define gabyun A1
int buttonState = 0;      // 버튼 상태(눌렸는지 안 눌렸는지)를 저장하는 변수
int lastButtonState = 0;  // 이전 버튼 상태를 저장하는 변수
int led1State = LOW;
int led2State = LOW;   
       // LED 상태(켜짐 또는 꺼짐)를 저장하는 변수

void setup() {
  pinMode(buttonPin, INPUT);  // 버튼 핀을 입력으로 설정
  pinMode(resPin, INPUT);
  pinMode(ledPin1, OUTPUT);
  pinMode(ledPin2, OUTPUT);    // LED 핀을 출력으로 설정
  Serial.begin(9600);
}

void loop() {
  buttonState = digitalRead(buttonPin);  
   delay(100);  // 디바운싱을 위한 짧은 지연 읽어옴에 대한 지연을 줘야... 정확히 인식할듯
  int resState = analogRead(resPin);
  Serial.println(resState);

  // 버튼의 상태가 이전과 다르면 토글 동작 수행
  if (buttonState != lastButtonState) {
    if (buttonState == HIGH) {
      // 버튼이 눌렸을 때 LED 상태 토글
      if(led1State == LOW && led2State == LOW){
        led1State =1;
        // digitalWrite(ledPin1, led1State); 있으면안됨 한번만 쓰면 됨
      } else if(led1State == 1 && led2State == LOW){
        led2State = 1;
        // digitalWrite(ledPin2, led2State);
      }  else if(led1State == 1 && led2State == 1){
         led1State = 0;
        led2State = 0;
    }
    
        digitalWrite(ledPin1, led1State);
        digitalWrite(ledPin2, led2State);
  }

  lastButtonState = buttonState; 
  } // 현재 버튼 상태를 저장
}