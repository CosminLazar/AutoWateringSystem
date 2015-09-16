#include "ToggleSwitch.h"
#define ToggleSwitchChangeResiliency 5

ToggleSwitch::ToggleSwitch(uint8_t pin) :ToggleSwitch(pin, LOW)
{ }

ToggleSwitch::ToggleSwitch(uint8_t pin, uint8_t closedState)
{
	this->_pin = pin;
	this->_closedState = closedState;
	this->_pastReadings = 0;

	pinMode(this->_pin, INPUT_PULLUP);
}

void ToggleSwitch::Update() {
	if (digitalRead(this->_pin) == this->_closedState) {
		this->ClosedStateDetected();
	}
	else {
		this->OpenedStateDetected();
	}
}

bool ToggleSwitch::IsClosed()
{
	this->Update();

	if (this->_pastReadings == 0)
		this->Update();

	return this->_pastReadings > 0;
}

void ToggleSwitch::ClosedStateDetected()
{
	if (this->_pastReadings == ToggleSwitchChangeResiliency)
		return;

	this->_pastReadings += 1;
}

void ToggleSwitch::OpenedStateDetected()
{
	if (this->_pastReadings == ToggleSwitchChangeResiliency*(-1))
		return;

	this->_pastReadings -= 1;
}
