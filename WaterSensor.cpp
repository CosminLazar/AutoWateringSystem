// 
// 
// 

#include "WaterSensor.h"

WaterSensor::WaterSensor(uint8_t readingPin)
{	
	this->_readingPin = readingPin;
}

bool WaterSensor::HasWater()
{
	return false;
}
