// 
// 
// 

#include "WateringSystem.h"

WateringSystem::WateringSystem()
{
	this->_ambientalSensor = new AmbientalSensor(AmbientalTemperaturePin);
	this->_plantWaterSensor = new WaterSensor(PlantWaterSensorPin);
	this->_pumpWaterSensor = new WaterSensor(PumpWaterSensorPin);
	this->_waterPump = new WaterPump(WaterPumpPowerPin, this->_pumpWaterSensor);
	this->_waterPumpManualOverride = new ToggleSwitch(WaterPumpOverridePin);

	this->_userOverridenPump = new UserOverridenWateringState(*(this->_waterPumpManualOverride), *(this->_waterPump));

	IdleSystemState* idleState = new IdleSystemState(*(this->_ambientalSensor));
	this->_currentState = idleState;
	this->_currentState->EnterState();

	//lower index value means higher priority
	this->_systemStates[0] = this->_userOverridenPump;
	this->_systemStates[1] = idleState;
}

void WateringSystem::Update(Graphics* graphics)
{
	CpuSpinner::Update();

	//todo: a state with a higher priority and enterable should be able to force it out
	if (this->_currentState->CanLeaveState()) {

		SystemState* nextState = NULL;
		for (uint8_t i = 0; i < KnownStatesCount; i++)
		{
			SystemState* currentState = this->_systemStates[i];

			if (currentState->CanEnterState()) {
				nextState = currentState;
				break;
			}
		}

		if (nextState != NULL && this->_currentState != nextState) {
			this->_currentState->LeaveState();
			nextState->EnterState();
			this->_currentState = nextState;
			graphics->Clear();//give a clear screen to work with
		}
	}

	//RENDER STATE
	this->_currentState->Render(*graphics);
	
	/*
	states:
		4-defaultState - show ambiental temperature, air humidity, soil humidity and some graphics
		3-wateringState - while watering the plant
		2-manualOverrideState
		1-missingWaterState
	*/
}
