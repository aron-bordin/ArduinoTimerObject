#include "TimerObject.h"

TimerObject::TimerObject(int ms){
	Create(ms, NULL, false);
}

TimerObject::TimerObject(int ms, CallBackType callback){
	Create(ms, callback, false);
}

TimerObject::TimerObject(int ms, CallBackType callback, bool isSingle){
	Create(ms, callback, isSingle);
}

void TimerObject::Create(int ms, CallBackType callback, bool isSingle){
	setInterval(ms);
	setEnabled(false);
	setSingleShot(isSingle);
	setOnTimer(callback);
	LastTime = 0;
}

void TimerObject::setInterval(int ms){
	msInterval = (ms > 0) ? ms : 0;
}

void TimerObject::setEnabled(bool Enabled){
	blEnabled = Enabled;
}

void TimerObject::setSingleShot(bool isSingle){
	blSingleShot = isSingle;
}

void TimerObject::setOnTimer(CallBackType callback){
	onRun = callback;
}

void TimerObject::Start(){
	LastTime = millis();
	setEnabled(true);
}

void TimerObject::Resume(){
	LastTime = millis() - DiffTime;
	setEnabled(true);
}

void TimerObject::Stop(){
	setEnabled(false);

}

void TimerObject::Pause(){
	DiffTime = millis() - LastTime;
	setEnabled(false);

}

void TimerObject::Update(){
	if(Tick())
		onRun();
}

bool TimerObject::Tick(){
	if(!blEnabled)
		return false;
	if ((int)(millis() - LastTime) >= msInterval) {
		LastTime = millis();
		if(isSingleShot())
			setEnabled(false);
	    return true;
	}
	return false;
}


int TimerObject::getInterval(){
	return msInterval;
}

CallBackType TimerObject::getOnTimerCallback(){
	return onRun;
}

bool TimerObject::isEnabled(){
	return blEnabled;
}

bool TimerObject::isSingleShot(){
	return blSingleShot;
}
