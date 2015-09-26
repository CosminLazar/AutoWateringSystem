// UserOverridenWateringState.h

#ifndef _USEROVERRIDENWATERINGSTATE_h
#define _USEROVERRIDENWATERINGSTATE_h

#include "SystemState.h"
#include "ToggleSwitch.h"
#include "WaterPump.h"
#include "Graphics.h"
#include "WateringManImg.h"
#include "HumidityImg.h"
#include "SunImg.h"
#include "WateringCanImg.h"

#if defined(ARDUINO) && ARDUINO >= 100
#include "arduino.h"
#else
#include "WProgram.h"
#endif

class UserOverridenWateringState : public SystemState {
private:
	ToggleSwitch& _manualOverrideSwitch;
	WaterPump& _waterPump;
	WateringManImg _wateringManImg;
public:
	UserOverridenWateringState(ToggleSwitch& manualOverrideSwitch, WaterPump& waterPump) 
		:_manualOverrideSwitch(manualOverrideSwitch), _waterPump(waterPump) {}
	bool CanEnterState();
	void EnterState();
	bool CanLeaveState();
	void LeaveState();	
	void Render(Graphics& graphics);
};
#endif

