// 
// 
// 

#include "WaterPump.h"

WaterPump::WaterPump(uint8_t powerPin, WaterSensor* waterSensor)
{
	this->_powerPin = powerPin;
	this->_waterSensor = waterSensor;

	pinMode(this->_powerPin, OUTPUT);
	digitalWrite(this->_powerPin, LOW);
}

WaterPump::WaterPump(uint8_t powerPin) : WaterPump(powerPin, NULL)
{ }

bool WaterPump::Start()
{
	if (!this->HasWater())
		return false;

	digitalWrite(this->_powerPin, HIGH);

	return true;
}

void WaterPump::Stop()
{
	digitalWrite(this->_powerPin, LOW);
}

bool WaterPump::HasWater()
{
	if (this->_waterSensor == NULL)
		return true;

	return this->_waterSensor->HasWater();
}
