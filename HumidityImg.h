// HumidityImg.h

#ifndef _HUMIDITYIMG_h
#define _HUMIDITYIMG_h

#include "XbmImage.h"
#include "ResourceStreamer.h"

#if defined(ARDUINO) && ARDUINO >= 100
#include "arduino.h"
#else
#include "WProgram.h"
#endif

class HumidityImg : public XbmImage {
public:
	uint8_t GetWidth();
	uint8_t GetHeight();
	ResourceStreamer GetStream();
};

#endif

