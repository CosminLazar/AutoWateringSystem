#include "IdleSystemState.h"

bool IdleSystemState::CanEnterState()
{
	return true;
}

void IdleSystemState::EnterState()
{
	this->_shouldRender = true;
}

bool IdleSystemState::CanLeaveState()
{
	return true;
}

void IdleSystemState::LeaveState()
{

}

void IdleSystemState::DoWork()
{
	if (this->ShouldUpdateAmbientalSensorData()) {
		this->UpdateAmbientalSensorData();
	}
}

bool IdleSystemState::ShouldUpdateAmbientalSensorData() {
	unsigned long now = millis();
	return (now - this->_lastAmbientalSensorPool) > this->AmbientalSensorPoolingInterval;
}

void IdleSystemState::UpdateAmbientalSensorData() {	
	this->_ambientalSensorData = this->_ambientalSensor.Read();
	this->_lastAmbientalSensorPool = millis();
	this->_shouldRender = true;
}

void IdleSystemState::Render(Graphics & graphics)
{
	if (!this->_shouldRender)
		return;

	this->_shouldRender = false;

	this->RenderStaticGraphics(graphics);

	if (this->_ambientalSensorData.HasError()) {
		const char * unknownValue = "?";
		this->RenderTemperature(unknownValue, graphics);
		this->RenderAirHumidity(unknownValue, graphics);
	}
	else
	{
		char temperature[7];
		dtostrf(this->_ambientalSensorData.TemperatureInCelsius(), 5, 1, temperature);
		strcat(temperature, " C");
		this->RenderTemperature(temperature, graphics);

		char airHumidity[4];
		dtostrf(this->_ambientalSensorData.Humidity(), 2, 0, airHumidity);
		strcat(airHumidity, " %");
		this->RenderAirHumidity(airHumidity, graphics);
	}

	this->RenderSoilHumidity("15 %", graphics);
}

void IdleSystemState::RenderStaticGraphics(Graphics & graphics) {
	graphics.Draw_Xbm(0, 0, this->_sunImg);
	graphics.Draw_Xbm(0, 4, this->_wateringCanImg);

	ThermometerImg t;
	HumidityImg h;
	graphics.Draw_Xbm(50, 0, t);
	graphics.Draw_Xbm(46, 4, h);
}

void IdleSystemState::RenderTemperature(const char * value, Graphics & graphics) {
	graphics.Print(value, s8x16, 70, 0);
}
void IdleSystemState::RenderAirHumidity(const char * value, Graphics & graphics) {
	graphics.Print(value, s8x16, 95, 4);
}
void IdleSystemState::RenderSoilHumidity(const char * value, Graphics & graphics) {
	graphics.Print(value, s8x16, 95, 6);
}