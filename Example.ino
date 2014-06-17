#include "TimerObject.h"

TimerObject *t = new TimerObject(1000);

void setup(){
	Serial.begin(9600);
	t->setOnTimer(&PrintHello);
	t->Start();

}

void PrintHello(){
	Serial.println("Hello timer!!");
}

void loop(){
	t->Update();

}