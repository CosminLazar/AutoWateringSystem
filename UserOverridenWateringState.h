// UserOverridenWateringState.h

#ifndef _USEROVERRIDENWATERINGSTATE_h
#define _USEROVERRIDENWATERINGSTATE_h

#include "SystemState.h"
#include "ToggleSwitch.h"
#include "WaterPump.h"

#if defined(ARDUINO) && ARDUINO >= 100
#include "arduino.h"
#else
#include "WProgram.h"
#endif

class UserOverridenWateringState : public SystemState {
private:
	ToggleSwitch& _manualOverrideSwitch;
	WaterPump& _waterPump;
public:
	UserOverridenWateringState(ToggleSwitch& manualOverrideSwitch, WaterPump& waterPump) 
		:_manualOverrideSwitch(manualOverrideSwitch), _waterPump(waterPump) {}
	bool CanEnterState();
	void EnterState();
	bool CanLeaveState();
	void LeaveState();
};
#endif

