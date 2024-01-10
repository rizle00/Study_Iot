int ledB = 9, ledG =10, ledR =11;

void setup() {
  pinMode(ledB, OUTPUT);
   pinMode(ledG, OUTPUT);
    pinMode(ledR, OUTPUT);
    Serial.begin(9600);

}

void loop() {
  while(Serial.available()>0){
  char input = Serial.read();
  Serial.println(input);
  if(input =='1'){
    analogWrite(ledR, 255);
  }else if(input =='2'){
    analogWrite(ledG, 255);
  }else if(input =='3'){
    analogWrite(ledB, 255);
  }else if(input =='4'){
    analogWrite(ledR, 0);
    analogWrite(ledG, 0);
    analogWrite(ledB, 0);
  }
  }
  

}
