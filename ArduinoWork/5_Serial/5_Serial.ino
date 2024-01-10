 int count = 0;
String str = "";
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);

}

void loop() {

  // put your main code here, to run repeatedly:
// 시리얼 버퍼에 데이터가 있는지 확인 하는 함수 ->( 있으면 1, 없으면 0)
// 루프를 돌리는 것과 while 을 돌리는 것의 시간 차가 있어서 delay 필요..
  while(Serial.available()){
    // char c = Serial.read();
    count ++;
    Serial.print(count);
    Serial.print(":");
    // Serial.println(c);
    // str += c;
    int num = Serial.parseInt();
    Serial.println(num);
    delay(10);
  }
  delay(10);
 count =0;
}
