int randomNum = 0;
int inputNum =0;
void printRandom();

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  // int analogRead = analogRead(A0);
  randomSeed(analogRead(A0));
  // Serial.println(analogRead(A0));
  printRandom();

}

void loop() {
  // put your main code here, to run repeatedly:
  if(Serial.available()>0){
   int inputNum = Serial.parseInt();
    // Serial.print(inputNum);
    if(randomNum == inputNum){
      Serial.print(inputNum);
      Serial.println(" : 정답");
        // return; loop 자체를 종료할 수 는 없음
        // Serial.end();
        // setup();// 다시 셋업을 호출해야함
        printRandom();
    } else {
      Serial.print(inputNum);
       Serial.println(" : 오답");
    }
  }

}

void printRandom(){
   Serial.println();
  Serial.println("Making Random Number....");
  Serial.println("Start");
  randomNum = random(1,10);
}