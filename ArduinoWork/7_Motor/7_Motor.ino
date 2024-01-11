int A_motor_speed = 10, A_motor_L =8, A_motor_R =9;


// #include <AFMotor.h>
// AF_DCMotor motor(1);  // 1번 모터를 사용합니다. 필요에 따라 모터 번호를 변경하세요.

void setup() {
  // 모터 초기화 및 설정
  // motor.setSpeed(255);  // 모터 속도 설정 (0부터 255까지)
  pinMode(A_motor_L, OUTPUT);
  pinMode(A_motor_R, OUTPUT);
  pinMode(A_motor_speed, OUTPUT);

}

void loop() {
  // 모터를 시계방향으로 회전
  // motor.run(FORWARD);
  // delay(1000);  // 1초 동안 대기

  // // 모터를 정지
  // motor.run(RELEASE);
  // delay(1000);  // 1초 동안 대기

  // // 모터를 반시계방향으로 회전
  // motor.run(BACKWARD);
  // delay(1000);  // 1초 동안 대기

  // // 모터를 정지
  // motor.run(RELEASE);
  // delay(1000);  // 1초 동안 대기
  digitalWrite(A_motor_L, HIGH);
  digitalWrite(A_motor_R, LOW);
  analogWrite(A_motor_speed, 50);
  delay(1000);
  analogWrite(A_motor_speed, 0);
  digitalWrite(A_motor_L, LOW);
   delay(3000);
   digitalWrite(A_motor_L, LOW);
  digitalWrite(A_motor_R, HIGH);
  analogWrite(A_motor_speed, 50);
  delay(1000);
  analogWrite(A_motor_speed, 0);
   digitalWrite(A_motor_R, LOW);
  delay(3000);
}
