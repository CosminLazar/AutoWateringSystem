// 
// 
// 

#include "ToggleSwitch.h"

ToggleSwitch::ToggleSwitch(uint8_t pin) :ToggleSwitch(pin, LOW)
{ }

ToggleSwitch::ToggleSwitch(uint8_t pin, uint8_t onState)
{
	this->_pin = pin;
	this->_onState = onState;

	pinMode(this->_pin, INPUT_PULLUP);
}

bool ToggleSwitch::IsOn()
{
	return false;
}
