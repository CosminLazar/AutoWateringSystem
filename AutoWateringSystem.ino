#include "ResourceStreamer.h"
#include "WateringMan.h"
#include "XbmImage.h"
#include "IdleSystemState.h"
#include "UserOverridenWateringState.h"
#include "SystemState.h"
#include "CpuSpinner.h"
#include "ToggleSwitch.h"
#include "PinReservation.h"
#include <DHTSensor.h>
#include <IIC_without_ACK.h>
#include "Graphics.h"
#include "AmbientalSensor.h"
#include "WaterSensor.h"
#include "WaterPump.h"
#include "WateringSystem.h"

Graphics* _graphics;
WateringSystem* _system;

void setup()
{
	Serial.begin(9600);
	_graphics = new Graphics(OLED_SDA, OLED_SCL);

	_system = new WateringSystem();
}

void loop()
{
	_system->Update(_graphics);
}

