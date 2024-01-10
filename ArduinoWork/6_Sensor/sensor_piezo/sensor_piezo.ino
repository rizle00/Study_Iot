#define C 131  // 도
#define D 147  // 레
#define E 165  // 미
#define F 175  // 파
#define G 196  // 솔
#define A 220  // 라
#define B 247  // 시
int notes[25] = {G, G, A, A, G, G, E, G, G, E, E, D, G, G, A, A, G, G, E, G, E, D, E, C };
#define D5 587
#define E5 659
#define F5 698
#define G5 783
#define A5 880
#define B4 494
#define B5 987
#define C6 1046

int note[] = {D5, A4, B4, F5, G5, D5, G5, A5, D5, A4, B4, F5, G5, D5, G5, A5,
               B5, G5, F5, E5, D5, E5, F5, G5, A5, F5, G5, A5, B5, A5, G5, F5};

int durations[] = {8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8,
                   8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8};
int piezoPin =7, tempo = 200;
void playMelody();

void setup() {
 
  pinMode(piezoPin, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  if(Serial.available()){
    char input = Serial.read();
    if(input == 'y'){
    //   for(int i =0; i<25; i++){
    // tone(piezoPin, notes[i], tempo);
    // delay(300);
    // if(i==12) delay(400);
    playMelody();
  }
    }
    
  }  
  


void playMelody() {
  for (int i = 0; i < sizeof(note) / sizeof(note[0]); i++) {
    playNote(note[i], 200 * durations[i]); // 각 음표에 150ms의 고정된 속도를 적용
  }
}

void playNote(int note, int duration) {
  tone(piezoPin, note, duration); // 8번 핀에서 note 주파수의 소리를 duration(ms) 동안 연주
  delay(duration + 50);    // 50ms 추가 딜레이로 음 사이의 간격을 주어 구분
  noTone(8);               // 음 연주 중지
}