const int analogPin = A0;   // 가변 저항이 연결된 아날로그 핀
const int ledPin = 9;       // LED가 연결된 디지털 핀

void setup() {
  pinMode(analogPin, INPUT);
  pinMode(ledPin, OUTPUT);  // LED 핀을 출력으로 설정
  Serial.begin(9600);       // 시리얼 통신 설정
}

void loop() {
  int sensorValue = analogRead(analogPin);  // 가변 저항의 값 읽어오기
  int ledBrightness = map(sensorValue, 1023, 0, 0, 255);  // 값을 LED 밝기 범위로 변환

  analogWrite(ledPin, ledBrightness);  // LED 밝기 조절
  Serial.println(sensorValue);  // 시리얼 모니터에 가변 저항 값 출력
  delay(50);  // 임의의 지연 시간
}