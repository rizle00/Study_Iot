

int ledR =11, ledG =10, ledB = 9;

void setup() {
  // put your setup code here, to run once:
    pinMode(ledR, OUTPUT);
    pinMode(ledG, OUTPUT);
    pinMode(ledB, OUTPUT);
    // for( int i = 9; i<=11; i++){
    //   pinMode(i, OUTPUT)
    // }
}

void loop() {
  // put your main code here, to run repeatedly:
  analogWrite(ledR, 255);
    delay(1000);
    analogWrite(ledG, 255);
    delay(1000);
    analogWrite(ledB, 255);
    delay(1000);
    analogWrite(ledR, 0);
    delay(1000);
    analogWrite(ledG, 0);
    delay(1000);
    analogWrite(ledB, 0);
    delay(1000);

     analogWrite(ledR, 182);    
    analogWrite(ledG, 102);
    analogWrite(ledB, 210);
    delay(2000);

  for(int i = 0 ; i<256; i+=10){
    for(int j = 255 ; j>0; j-=7){
      for(int k = 0 ; k<256; k+=15){
    analogWrite(ledR, k);
    analogWrite(ledG, j);
    analogWrite(ledB, i);
    delay(5);
      }
    }
  }
    
}
