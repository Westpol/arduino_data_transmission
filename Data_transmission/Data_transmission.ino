#include "math.h"

#define CLK_PIN 2
#define TX_PIN 3

bool byte_array[8] = {0, 0, 0, 0, 0, 0, 0, 0};

void setup() {
  //Serial.begin(9600);
  pinMode(LED_BUILTIN, OUTPUT);
  pinMode(CLK_PIN, INPUT_PULLUP);
  pinMode(TX_PIN, INPUT_PULLUP);
  
}

void loop() {
  negotiate();
  delay(100);
  sendMessage("Hello, World!");
  delay(100);
  pinMode(LED_BUILTIN, OUTPUT);
  pinMode(CLK_PIN, INPUT_PULLUP);
  pinMode(TX_PIN, INPUT_PULLUP);
  delay(5000);
}


void negotiate(){
  digitalWrite(TX_PIN, LOW);
  while(digitalRead(CLK_PIN)){}
  digitalWrite(CLK_PIN, LOW);
  digitalWrite(TX_PIN, LOW);
  pinMode(LED_BUILTIN, OUTPUT);
  pinMode(CLK_PIN, OUTPUT);
  pinMode(TX_PIN, OUTPUT);
}


void sendMessage(String msg){

  for(int k = 0; k < msg.length(); k++){  //loop through every ASCII Character

    digitalWrite(CLK_PIN, LOW); //set everything to 0
    digitalWrite(TX_PIN, LOW);

    int subj = (int) msg[k];
    for(int i = 8; i >= 0; i--){  //get bit array
      if(subj >= pow(2, i)){
        byte_array[7 - i] = true;
        subj -= pow(2, i);
      }
      else {
        byte_array[7 - i] = false;
      }
    }


    delay(1000);  //wait between TXes
  
    for(int i = 0; i < 8; i++){   //transmit 8 bits
      digitalWrite(TX_PIN, byte_array[i]);
      delay(50);
      digitalWrite(CLK_PIN, HIGH);
      digitalWrite(LED_BUILTIN, HIGH);
      delay(50);
      digitalWrite(CLK_PIN, LOW);
      digitalWrite(LED_BUILTIN, LOW);
    }
    digitalWrite(LED_BUILTIN, LOW);
  }
}