#include "UserOverridenWateringState.h"
bool UserOverridenWateringState::CanEnterState() {
	return this->_manualOverrideSwitch.IsClosed();
}

void UserOverridenWateringState::EnterState()
{
	this->_waterPump.Start();
}

bool UserOverridenWateringState::CanLeaveState() {
	return (!this->_manualOverrideSwitch.IsClosed());
}

void UserOverridenWateringState::LeaveState()
{
	this->_waterPump.Stop();
}

void UserOverridenWateringState::Render(Graphics & graphics)
{
	uint8_t centerX = (graphics.GetWidth() / 2) - (this->_wateringManImg.GetWidth() / 2);
	graphics.Draw_Xbm(centerX, 0, this->_wateringManImg);
}
