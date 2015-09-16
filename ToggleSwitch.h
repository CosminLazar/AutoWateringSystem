// ToggleSwitch.h

#ifndef _TOGGLESWITCH_h
#define _TOGGLESWITCH_h


#if defined(ARDUINO) && ARDUINO >= 100
#include "arduino.h"
#else
#include "WProgram.h"
#endif

class ToggleSwitch {
public:
	ToggleSwitch(uint8_t pin);
	ToggleSwitch(uint8_t pin, uint8_t onState);

	bool IsOn();
private:
	uint8_t _pin;
	uint8_t _onState;
};

#endif