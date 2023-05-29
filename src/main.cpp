#include <Arduino.h>

#define R_IN 26
#define G_IN 27
#define B_IN 28

#define R_OUT 7
#define G_OUT 6
#define B_OUT 5

int r = 0;
int g = 0;
int b = 0;

void setup() {
  // put your setup code here, to run once:
  pinMode(R_OUT, OUTPUT);
  pinMode(G_OUT, OUTPUT);
  pinMode(B_OUT, OUTPUT);
  pinMode(R_IN, INPUT_PULLDOWN);
  pinMode(G_IN, INPUT_PULLDOWN);
  pinMode(B_IN, INPUT_PULLDOWN);
  pinMode(25, OUTPUT); // internal led
  Serial.begin(115200);
}

void loop() {
  /*if(digitalRead(B_IN) == LOW && digitalRead(R_IN) == LOW && digitalRead(G_IN) == LOW){
    digitalWrite(R_OUT, LOW);
    digitalWrite(G_OUT, LOW);
    digitalWrite(B_OUT, LOW);
    sleep_ms(1000);
    
  }*/
  if(analogRead(R_IN) > 500 && r != 255){r++;}
  else if(r != 0){r--;}
  if(analogRead(G_IN) > 500 && g != 255){g++;}
  else if(g != 0){g--;}
  if(analogRead(B_IN) > 500 && b != 255){b++;}
  else if(b != 0){b--;}

  /*if(digitalRead(R_IN) && r != 255){r=255;}
  else if(digitalRead(R_IN) == LOW && r != 0){r=0;}
  if(digitalRead(G_IN) && r != 255){g=255;}
  else if(digitalRead(G_IN) == LOW && g != 0){g=0;}
  if(digitalRead(B_IN) && r != 255){b=255;}
  else if(digitalRead(B_IN) == LOW && b != 0){b=0;}*/


  analogWrite(R_OUT, r);
  analogWrite(25, r);
  analogWrite(G_OUT, g);
  analogWrite(B_OUT, b);
  /*Serial.println(r);
  Serial.println(g);
  Serial.println(b);*/

  Serial.println(analogRead(R_IN));
  Serial.println(analogRead(G_IN));
  Serial.println(analogRead(B_IN));

  Serial.println("");
  delay(10);
}
