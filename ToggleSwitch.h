// ToggleSwitch.h

#ifndef _TOGGLESWITCH_h
#define _TOGGLESWITCH_h

#include "CpuSpinner.h"
#if defined(ARDUINO) && ARDUINO >= 100
#include "arduino.h"
#else
#include "WProgram.h"
#endif

class ToggleSwitch {
public:
	ToggleSwitch(uint8_t pin);
	ToggleSwitch(uint8_t pin, uint8_t closedState);

	void Update();
	bool IsClosed();
	static void UpdateCallbackWrapper(void* instance);
private:
	uint8_t _pin;
	uint8_t _closedState;
	int8_t _pastReadings;

	void ClosedStateDetected();
	void OpenedStateDetected();
};

#endif