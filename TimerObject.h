#include "stdlib.h"
#include "Arduino.h"

#ifndef TIMER_OBJECT_H
#define TIMER_OBJECT_H
typedef void (*CallBackType)();


class TimerObject{
private:
	void Create(int ms, CallBackType callback, bool isSingle);
	int msInterval;
	bool blEnabled;
	bool blSingleShot;
	CallBackType onRun;
	bool Tick();
	unsigned long LastTime;
	unsigned long DiffTime;//used when I pause the Timer and need to resume

public:
	TimerObject(int ms);
	TimerObject(int ms, CallBackType callback);
	TimerObject(int ms, CallBackType callback, bool isSingle);
	~TimerObject();

	void setInterval(int ms);
	void setEnabled(bool Enabled);
	void setSingleShot(bool isSingle);
	void setOnTimer(CallBackType callback);
	void Start();
	void Resume();
	void Pause();
	void Stop();
	void Update();


	int getInterval();
	CallBackType getOnTimerCallback();

	bool isEnabled();
	bool isSingleShot();

};


#endif // TIMER_OBJECT_H
