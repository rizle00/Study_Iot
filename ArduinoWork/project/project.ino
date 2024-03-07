#include <SoftwareSerial.h>
#include <Wire.h>
#include <Adafruit_MLX90614.h>
#define USE_ARDUINO_INTERRUPTS true    // Set-up low-level interrupts for most acurate BPM math.
#include <PulseSensorPlayground.h>     // Includes the PulseSensorPlayground Library.   

SoftwareSerial BTSerial(8,7);
const int PulseWire = A2;       // PulseSensor PURPLE WIRE connected to ANALOG PIN A2
const int btn = 10;
Adafruit_MLX90614 mlx = Adafruit_MLX90614();
PulseSensorPlayground pulseSensor;  // Creates an instance of the PulseSensorPlayground object called "pulseSensor"
float temp;
int index = 0;

void setup() {
  
Serial.begin(9600);        
BTSerial.begin(9600);     //블루투스 
pinMode(btn, INPUT); // 버튼
mlx.begin();  //온도센서
pulseSensor.analogInput(PulseWire);   
pulseSensor.setThreshold(550);//심박 딜레이 기본 값
// if (pulseSensor.begin()) {
//     Serial.println("We created a pulseSensor Object !");  //This prints one time at Arduino power-up,  or on Arduino reset.  
//   }
}

void loop() {
  int myBPM = pulseSensor.getBeatsPerMinute(); // 심박
  temp += mlx.readObjectTempC(); // 체온 c
  index++;
  //0 1 2 3 4 (5)
  if(index >= 5){
    //결과출력
    temp = temp/5;
    Serial.println(temp);
    temp = 0;
    index =0;
  }
  // Serial.print("Ambient = "); Serial.print(mlx.readAmbientTempC()); 
  // Serial.print("*C\tObject = "); Serial.print(mlx.readObjectTempC()); Serial.println("*C");

  

if(BTSerial.available())//  블루투스에서 데이터 보냄
        Serial.write(BTSerial.read());

if(Serial.available())
        BTSerial.write(Serial.read());   
delay(500);
}
