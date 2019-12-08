#include <ArduinoJson.h>

const int capacity = JSON_OBJECT_SIZE(3);
StaticJsonDocument<capacity> doc;

void setup() {
  // initialize digital pin LED_BUILTIN as an output.
  pinMode(D2, OUTPUT);
  Serial.begin(115200);
}

// the loop function runs over and over again forever
void loop() {
  doc["LDR"] = analogRead(A0);
  doc["LED"] = digitalRead(D2);
  serializeJson(doc,Serial);
  if( Serial.available() > 0 ){
    deserializeJson(doc,Serial);
    if( doc["LED"] == 1){
      digitalWrite(D2,HIGH);
    }else if ( doc["LED"] == 0){
      digitalWrite(D2,LOW);
    }
  }
  delay(1000);                       
}
