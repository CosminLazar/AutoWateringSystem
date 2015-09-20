// WaterPump.h

#ifndef _WATERPUMP_h
#define _WATERPUMP_h

#include "WaterSensor.h"

#if defined(ARDUINO) && ARDUINO >= 100
#include "arduino.h"
#else
#include "WProgram.h"
#endif

class WaterPump
{
public:
	WaterPump(uint8_t powerPin, WaterSensor* waterSensor);
	WaterPump(uint8_t powerPin);
	bool Start();
	void Stop();
private:
	WaterSensor* _waterSensor;
	uint8_t _powerPin;	
	bool HasWater();
};

#endif

