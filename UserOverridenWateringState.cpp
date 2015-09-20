#include "UserOverridenWateringState.h"
bool UserOverridenWateringState::CanEnterState() {
	return this->_manualOverrideSwitch.IsClosed();
}

void UserOverridenWateringState::EnterState()
{
	this->_waterPump.Start();
}

bool UserOverridenWateringState::CanLeaveState() {
	return !this->_manualOverrideSwitch.IsClosed();
}

void UserOverridenWateringState::LeaveState()
{
	this->_waterPump.Stop();
}
