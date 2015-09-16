// 
// 
// 

#include "AmbientalSensor.h"

AmbientalSensor::AmbientalSensor(uint8_t dataPin)
{
	this->_sensor = new DHTSensor(dataPin);
}
