// SystemState.h

#ifndef _SYSTEMSTATE_h
#define _SYSTEMSTATE_h

#if defined(ARDUINO) && ARDUINO >= 100
#include "arduino.h"
#else
#include "WProgram.h"
#endif

class SystemState {

public:
	virtual bool CanEnterState() = 0;
	virtual void EnterState() = 0;
	virtual bool CanLeaveState() = 0;
	virtual void LeaveState() = 0;
};
#endif

