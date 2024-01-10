
int sensor = A0, ledR = 11 , ledB =9;

void setup() {
  // put your setup code here, to run once:
  pinMode(sensor, INPUT);
  pinMode(ledR, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
 int input = analogRead(A0);
 if(input < 700){
  digitalWrite(ledB, HIGH);
 } else digitalWrite(ledB, LOW);
 analogWrite(ledR, map(input, 1023, 0, 0, 255));
 Serial.println(input);
 delay(200);
}
