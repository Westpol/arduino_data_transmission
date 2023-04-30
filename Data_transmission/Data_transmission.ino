#include "math.h"

#define CLK_PIN = 2;
#define TX_PIN = 3;

bool byte_array[8] = {0, 0, 0, 0, 0, 0, 0, 0};

void setup() {
  //Serial.begin(9600);
  pinMode(LED_BUILTIN, OUTPUT);
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  
}

void loop() {
  delay(5000);
  sendMessage("Hello, World!");
}

void sendMessage(String msg){
  for(int k = 0; k < msg.length(); k++){
    int subj = (int) msg[k];
    for(int i = 8; i >= 0; i--){
      if(subj >= pow(2, i)){
        byte_array[7 - i] = true;
        subj -= pow(2, i);
      }
      else {
        byte_array[7 - i] = false;
      }
    }
    delay(1000);
    for(int i = 0; i < 8; i++){
      digitalWrite(LED_BUILTIN, byte_array[i]);
      delay(500);
    }
    digitalWrite(LED_BUILTIN, LOW);
  }
}