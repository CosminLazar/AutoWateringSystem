// WateringSystem.h

#ifndef _WATERINGSYSTEM_h
#define _WATERINGSYSTEM_h

#include "CpuSpinner.h"
#include "PinReservation.h"
#include "WaterSensor.h"
#include "AmbientalSensor.h"
#include "WaterPump.h"
#include "ToggleSwitch.h"
#include "SystemState.h"
#include "UserOverridenWateringState.h"
#include "IdleSystemState.h"

#if defined(ARDUINO) && ARDUINO >= 100
#include "arduino.h"
#else
#include "WProgram.h"
#endif

#include "Graphics.h"

class WateringSystem {
public:
	WateringSystem();
	void Update(Graphics* graphics);

private:
	static const uint8_t KnownStatesCount = 2;
	DHTSensor* _ambientalSensor;
	WaterSensor* _pumpWaterSensor;
	WaterSensor* _plantWaterSensor;
	WaterPump* _waterPump;
	ToggleSwitch* _waterPumpManualOverride;
	SystemState* _userOverridenPump;
	SystemState* _systemStates[KnownStatesCount];
	SystemState* _currentState;
};
#endif