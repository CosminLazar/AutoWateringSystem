// XbmImage.h

#ifndef _XBMIMAGE_h
#define _XBMIMAGE_h

#include "ResourceStreamer.h"

#if defined(ARDUINO) && ARDUINO >= 100
#include "arduino.h"
#else
#include "WProgram.h"
#endif

class XbmImage {
public:
	virtual uint8_t GetWidth() = 0;
	virtual uint8_t GetHeight() = 0;	
	virtual ResourceStreamer GetStream() = 0;
};

#endif

