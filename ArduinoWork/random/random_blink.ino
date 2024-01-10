int randomNum = 0, inputNum =0;
int ledR =11 , ledB =10 ;

void printRandom();

void setup() {
  // put your setup code here, to run once:
  pinMode(ledB, OUTPUT);
  pinMode(ledR, OUTPUT);
  Serial.begin(9600);
  // int analogRead = analogRead(A0);
  randomSeed(analogRead(A0));
  // Serial.println(analogRead(A0));
  printRandom();

}

void loop() {
  // put your main code here, to run repeatedly:
  if(Serial.available()>0){
    delay(100);
    analogWrite(ledB, 0);
    analogWrite(ledR, 0);
   inputNum = Serial.parseInt();
    // Serial.print(inputNum);
    if(randomNum == inputNum){
      Serial.print(inputNum);
      Serial.println(" : 정답");
      analogWrite(ledB, 255);
        printRandom();
    } else {
      Serial.print(inputNum);
       Serial.println(" : 오답");
        analogWrite(ledR, 255);
        
    }
  }

}

void printRandom(){
   Serial.println();
  Serial.println("Making Random Number....");
  Serial.println("Start");
  randomNum = random(1,10);
}