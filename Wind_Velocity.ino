int sensor = 2;
int t;
int state;
int signal1;
int signal2;
int lastSensorState = 0;
float T;
float f;
void setup() {
Serial.begin(9600);
pinMode(sensor, INPUT);
}

void loop() {
  
  t = millis(); //t merr vleren aktuale te kohes qe arduino eshte ndezur
  
  state = digitalRead(sensor);

  //---I japim vlerat signal1 dhe signal2----//
  if(state != lastSensorState){
    if(state == HIGH && signal1 == 0){
      signal1 = t;
      }
    if(state == HIGH && signal1 != t){
      signal2 = t;
      }  
    }
  lastSensorState = state;
  
  //Serial.print("\nSignal 1 :");
  //Serial.print(signal1);
  //Serial.print("\nSignal 2 :");
  //Serial.print(signal2);
  
  T = signal2 - signal1; //perioda e nje rrotullimi
  T = T/1000; //e kthejme nga milisekonda ne sekonda  
  //Serial.print("\nPerioda :");
  //Serial.print(T);
  
  f = 1/T; //frekuenca e levizjes
  //Serial.print("\nFrekuenca :");
  //Serial.print(f);
  float rpm = f*60; //mqs frekuenca eshte numri i levizjeve ne sekonde, duke e shumezuar me 60 gjejme revolutions per minute
  Serial.print("\nRPM :");
  Serial.print(rpm);

  float v; //shpejtesia(velocity)
  float pi = 3.14159; //konstantja pi
  int D = 3; //diametri
  
  v = pi * D * rpm * 0.0166666667; //shpejtesia e levizjes se helikave => shpejtesia e eres
  Serial.print("\nShpejtesia :");
  Serial.print(v);
  Serial.print(" m/s");
  
  //kthjeme ne gjendje fillestare signa1 dhe signal2
  if(signal2 >= 1){
    signal1 = 0;
    signal2 = 0;
    }
}
