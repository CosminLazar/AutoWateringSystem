// IdleSystemState.h

#ifndef _IDLESYSTEMSTATE_h
#define _IDLESYSTEMSTATE_h

#include "SystemState.h"
#include "AmbientalSensor.h"

#if defined(ARDUINO) && ARDUINO >= 100
#include "arduino.h"
#else
#include "WProgram.h"
#endif

class IdleSystemState : public SystemState {
private:
	AmbientalSensor& _ambientalSensor;
public:
	IdleSystemState(AmbientalSensor& ambientalSensor) :_ambientalSensor(ambientalSensor) {}
	bool CanEnterState();
	void EnterState();
	bool CanLeaveState();
	void LeaveState();
};
#endif

