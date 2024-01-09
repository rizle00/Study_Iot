
int btn = 12;
int led = 13;
int btn_status = 0;
int last_btn_status = 0;
int led_status = 0;
// 필요한 정보들에 대해서 각각의 값이 필요함
void setup() {
  // put your setup code here, to run once:
  pinMode(btn, INPUT);
  pinMode(led, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  btn_status = digitalRead(btn); // 버튼의 눌림을 읽음
  Serial.println(btn_status);
  if(btn_status != last_btn_status){// 눌림 안눌림을 읽음 , 반복이 빨라서, 상태를 계속 읽어옴 -> 이게 중요함
     Serial.println(btn_status+"after");
    if(btn_status == 1){ // 버튼이 눌렸을 때 
      led_status = led_status == 0? 1: 0; // led 상태를 바꿈
      digitalWrite(led, led_status);
    }
  }
  delay(100);
  last_btn_status = btn_status; // 현재 버튼 상태 저장, 상태를 계속 반복해서 읽어옮으로 변화가 있을 때만..
  // int val  = digitalRead(btn);
  // Serial.println(val);
  // digitalWrite(led, val);
  // if(val = )
// if(val ==1){
//   btn_status = -btn_status;
//   val += btn_status;
//   digitalWrite(led, val);
// }
//  else{
//   digitalWrite(led, 0);
// }
}
