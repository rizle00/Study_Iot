#define C 262  // 도
#define D 294  // 레
#define E 330  // 미
#define F 349  // 파
#define G 392  // 솔
#define A 440  // 라
#define B 494  // 시
int notes[25] = {G, G, A, A, G, G, E, G, G, E, E, D, G, G, A, A, G, G, E, G, E, D, E, C };

int piezoPin =7, tempo = 200;

void setup() {
 
  pinMode(piezoPin, OUTPUT);
}

void loop() {
 for(int i =0; i<25; i++){
    tone(piezoPin, notes[i], tempo);
    delay(300);
    if(i==12) delay(100);
  }
}