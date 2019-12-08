#include "myled.h"
MyLed::MyLed(int p){
	pino = p;
  	pinMode(pino,OUTPUT);
}

void MyLed::acender(){
	digitalWrite(pino,HIGH);
}

void MyLed::apagar(){
	digitalWrite(pino,LOW);
}

void MyLed::blink(int intervalo){
	acender();
  	delay(intervalo);
  	apagar();
  	delay(intervalo);
  
}

void MyLed::dimmer(int valor){
  if(valor >= 0 and valor <=1023){
    	analogWrite(pino, valor);
  }	
}

void MyLed::fadeIn(int intervalo){

  for(int i=0; i<=255; i+=25){
    dimmer(i);
    delay(intervalo);
  }
}

void MyLed::fadeOut(int intervalo){

  for(int i=255; i>=0; i-=25){
    dimmer(i);
    delay(intervalo);
  }
}

int MyLed::getStatus(){
    return digitalRead(pino);
}