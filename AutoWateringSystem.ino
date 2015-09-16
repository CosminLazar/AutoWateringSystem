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
	_graphics = new Graphics(OLED_SDA, OLED_SCL);
	_system = new WateringSystem();
}

void loop()
{
	_system->Update(_graphics);
}

