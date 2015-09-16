// 
// 
// 

#include "WaterPump.h"

WaterPump::WaterPump(uint8_t powerPin, WaterSensor* waterSensor)
{
	this->_powerPin = powerPin;
	this->_waterSensor = waterSensor;
}

WaterPump::WaterPump(uint8_t powerPin) : WaterPump(powerPin, NULL)
{ }

bool WaterPump::HasWater()
{
	if (this->_waterSensor == NULL)
		return true;

	return this->_waterSensor->HasWater();
}
