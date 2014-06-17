#include "TimerObject.h"

TimerObject *timer1 = new TimerObject(1000);
TimerObject *timer2 = new TimerObject(500);


void setup(){
	Serial.begin(9600);
	timer1->setOnTimer(&PrintHello1);
	timer1->Start();

	timer2->setOnTimer(&PrintHello2);
	timer2->Start();

}

void PrintHello1(){
	Serial.println("Hello timer 1 !!");
}

void PrintHello2(){
	Serial.println("Hello timer 2!!");
}
void loop(){
	timer1->Update();
	timer2->Update();

}