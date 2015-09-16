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
}

void WateringSystem::Update(Graphics* graphics)
{
}
