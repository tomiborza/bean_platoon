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
