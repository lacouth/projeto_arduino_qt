#include <myled.h>
#include <ArduinoJson.h>

const int capacity = JSON_OBJECT_SIZE(3);
StaticJsonDocument<capacity> doc;

MyLed red(D2);

void setup() {
  Serial.begin(115200);
}

void loop() {
  doc["LDR"] = analogRead(A0);
  doc["LED"] = red.getStatus();
  
  serializeJson(doc,Serial);
  if( Serial.available() > 0 ){
    deserializeJson(doc,Serial);
    if( doc["LED"] == 1){
      red.acender();
    }else if ( doc["LED"] == 0){
      red.apagar();
    }
  }
  delay(1000);                       
}
