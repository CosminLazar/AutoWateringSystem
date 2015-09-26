// IdleSystemState.h

#ifndef _IDLESYSTEMSTATE_h
#define _IDLESYSTEMSTATE_h

#include "SystemState.h"
#include "AmbientalSensor.h"
#include "Graphics.h"
#include "SunImg.h"
#include "WateringCanImg.h"
#include "ThermometerImg.h"
#include "HumidityImg.h"

#if defined(ARDUINO) && ARDUINO >= 100
#include "arduino.h"
#else
#include "WProgram.h"
#endif

class IdleSystemState : public SystemState {
private:
	DHTSensor& _ambientalSensor;
	WateringCanImg _wateringCanImg;
	SunImg _sunImg;
	const uint32_t AmbientalSensorPoolingInterval = 30000;
	unsigned long _lastAmbientalSensorPool;
	bool _shouldRender = false;
	DHTSensorMeasurement _ambientalSensorData;
public:
	IdleSystemState(DHTSensor& ambientalSensor) :_ambientalSensor(ambientalSensor) {}
	bool CanEnterState();
	void EnterState();
	bool CanLeaveState();
	void LeaveState();
	void DoWork() override;
	void Render(Graphics& graphics);
private:
	void RenderStaticGraphics(Graphics & graphics);
	void RenderTemperature(const char * value, Graphics & graphics);
	void RenderAirHumidity(const char * value, Graphics & graphics);
	void RenderSoilHumidity(const char * value, Graphics & graphics);
	bool ShouldUpdateAmbientalSensorData();
	void UpdateAmbientalSensorData();
};
#endif

