// WaterSensor.h

#ifndef _WATERSENSOR_h
#define _WATERSENSOR_h

#if defined(ARDUINO) && ARDUINO >= 100
#include "arduino.h"
#else
#include "WProgram.h"
#endif

class WaterSensor
{
public:
	WaterSensor(uint8_t readingPin);
	bool HasWater();
private:	
	uint8_t _readingPin;
};


#endif

