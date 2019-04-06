#include <dht.h>
#define DHT11_PIN 7
dht DHT;
int s_onoff=8; // switch pin
bool s_val; //switch value
int zold=5;
int piros=3;
void setup(){
  
  Serial.begin(57600);
  pinMode(zold, OUTPUT);
  pinMode(piros,OUTPUT);
  pinMode(s_onoff,INPUT_PULLUP);
}

void loop(){
  //start of temperaturehumidity sensor
  int chk = DHT.read11(DHT11_PIN);
  Serial.print("Temperature = ");
  Serial.println(DHT.temperature);
  Serial.print("Humidity = ");
  Serial.println(DHT.humidity);
  //end of temperature humidity sensor
  Serial.println(analogRead(A0));  //soil humidity
  s_val=digitalRead(s_onoff);      
  if(s_val==LOW ){      //switching the system on/off
  analogWrite(piros,LOW);
  analogWrite(zold,20);
  
  }else {
  analogWrite(zold,LOW);                  
  analogWrite(piros,10);
  Serial.println(s_val);
  
  }
}
