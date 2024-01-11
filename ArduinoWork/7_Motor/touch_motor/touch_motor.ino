int A_motor_speed = 10, A_motor_L =8, A_motor_R =9;
int touch_sensor = A0;
int threshold = 800; 

void setup() {
  // put your setup code here, to run once:
  pinMode(A_motor_L, OUTPUT);
  pinMode(A_motor_R, OUTPUT);
  pinMode(A_motor_speed, OUTPUT);
  pinMode(touch_sensor, INPUT);
  Serial.begin(9600);

}

void loop() {
  // put your main code here, to run repeatedly:

    int sensorValue  =  analogRead(touch_sensor);
     Serial.print("Sensor Value: ");
     Serial.println(sensorValue);
      delay(1000);
    if (sensorValue > threshold) {
    Serial.println("Touch Detected!");
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
  

}
