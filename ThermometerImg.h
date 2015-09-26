// TemperatureImg.h

#ifndef _THERMOMETERIMG_h
#define _THERMOMETERIMG_h

#include "XbmImage.h"

#if defined(ARDUINO) && ARDUINO >= 100
#include "arduino.h"
#else
#include "WProgram.h"
#endif

class ThermometerImg : public XbmImage {
public:
	uint8_t GetWidth();
	uint8_t GetHeight();
	ResourceStreamer GetStream();
};
#endif

