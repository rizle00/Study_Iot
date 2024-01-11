#include <SoftwareSerial.h>
int r =7, g = 5, b =3;

SoftwareSerial bluetooth(9,10); // tx , rx
// #include <SoftwareSerial.h>

// SoftwareSerial bluetooth(10, 11);   // RX:11, TX:10 => 연결 반대로

// 시리얼모니터 열고
// AT 엔터 -> 응답 OK
// AT+NAMEXXXXXX -> 응답 OKsetname : 이름변경
// AT+PIN1234 -> 응답 OKsetPIN : 비밀번호변경
// AT+BAUD4 ->   응답 OK9600 : 통신속도변경 
//               1 -> 1200  2 -> 2400  3 -> 4800  4 -> 9600  5 ->19200  6 -> 38400  7 -> 57600  8 -> 115200
// AT+ROLE=S ->  응답 OK+ROLE:S   =>   M: Master S: Slave (기본 SLAVE 변경안해줘도 됨)

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  bluetooth.begin(9600);
  pinMode(r, OUTPUT);
  pinMode(g, OUTPUT);
  pinMode(b, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  if (bluetooth.available()) {
    
    // Serial.write(bluetooth.read());
    char input = bluetooth.read();
    Serial.print(input);
    if( input == '1'){
      digitalWrite(r, HIGH);
    } else  if(input == '2'){
      digitalWrite(g, HIGH);
    } else  if(input == '3'){
      digitalWrite(b, HIGH);
    } else if(input  == '4'){
      digitalWrite(r, LOW);
       digitalWrite(g, LOW);
        digitalWrite(b, LOW);
    }
    
  }

  if (Serial.available()) {
    
    bluetooth.write(Serial.read());
  }
}
