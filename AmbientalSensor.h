// AmbientalSensor.h

#ifndef _AMBIENTALSENSOR_h
#define _AMBIENTALSENSOR_h

#include <DHTSensor.h>

#if defined(ARDUINO) && ARDUINO >= 100
#include "arduino.h"
#else
#include "WProgram.h"
#endif

class AmbientalSensor
{
public:
	AmbientalSensor(uint8_t dataPin);

private:
	DHTSensor *_sensor;
};
#endif

