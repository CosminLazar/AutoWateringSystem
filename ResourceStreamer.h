// ResourceStreamer.h

#ifndef _RESOURCESTREAMER_h
#define _RESOURCESTREAMER_h

#if defined(ARDUINO) && ARDUINO >= 100
#include "arduino.h"
#else
#include "WProgram.h"
#endif

class ResourceStreamer {
private:
	const uint8_t * _resource;
	uint16_t _resourceSize;
	uint16_t _streamPosition;
public:
	ResourceStreamer(const uint8_t * resource, uint16_t resourceSize) : _resource(resource), _resourceSize(resourceSize), _streamPosition(0) {};

	//buffer - The buffer to read into
	//bufferSize - Number of bytes to read from stream (should equal the amount of preallocated memory)
	//return - Number of read bytes from the stream
	uint8_t ReadNext(uint8_t* buffer, uint8_t bufferSize);
};

#endif

