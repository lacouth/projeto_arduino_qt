#ifndef MYLED_H
#define MYLED_H

#include "Arduino.h"
class MyLed{
	private:
  		int pino;
  	public:
  		MyLed(int p);
  		void acender();
  		void apagar();
  		void blink(int intervalo);
  		void dimmer(int valor);
  		void fadeIn(int intervalo);
  		void fadeOut(int intervalo);
        int getStatus();
};

#endif