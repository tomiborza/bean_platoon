#include <dht.h>
#define DHT11_PIN 7
dht DHT;
int s_onoff=8; // switch pin
bool s_val; //switch value
int zold=5;
int piros=3;
int relay_pump=11;
int relay_fan=13;
void setup(){
  
  Serial.begin(57600);
  pinMode(relay_pump,OUTPUT);
  pinMode(relay_fan,OUTPUT);
  pinMode(zold, OUTPUT);
  pinMode(piros,OUTPUT);
  pinMode(s_onoff,INPUT_PULLUP);
}

void loop(){
  //start of temperaturehumidity sensor
  int chk = DHT.read11(DHT11_PIN);
  //end of temperature humidity sensor
  //Serial.println(analogRead(A0));  //soil humidity
  s_val=digitalRead(s_onoff);
  s_val=!s_val;      
  if(s_val==HIGH ){      //switching the system on/off
    
    analogWrite(piros,LOW);
    analogWrite(zold,20);
    Serial.println(s_val);
    if(analogRead(A0)<600){
      digitalWrite(relay_pump,HIGH);
      Serial.println("waterpump state: on");
    }else{
      digitalWrite(relay_pump,LOW);
      Serial.println("waterpump state: off");
    }
    if(DHT.temperature>28.00||DHT.humidity>55){
      digitalWrite(relay_fan,HIGH);
      Serial.println("fan state: on");
      
    }else{
      digitalWrite(relay_fan,LOW);
      Serial.println("fan state: off");
      
     }
      
    Serial.print("Soil Humidity Value = ");
    Serial.println(analogRead(A0));
    Serial.print("Temperature = ");
    Serial.println(DHT.temperature);
    Serial.print("Humidity = ");
    Serial.println(DHT.humidity);
  }else{
    analogWrite(zold,LOW);                  
    analogWrite(piros,10);
    Serial.println(s_val);
    digitalWrite(relay_fan,LOW);
    digitalWrite(relay_pump,LOW);
  }
  delay(500);
}

