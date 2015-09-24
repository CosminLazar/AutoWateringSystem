// Used to stream data from a program memory (flash) saved byte array
// 
// 

#include "ResourceStreamer.h"

uint8_t ResourceStreamer::ReadNext(uint8_t * buffer, uint8_t bufferSize)
{
	uint8_t bytesRead = 0;
	for (; this->_streamPosition < this->_resourceSize && bytesRead < bufferSize; this->_streamPosition++, bytesRead++)
	{
		buffer[bytesRead] = pgm_read_byte(&this->_resource[this->_streamPosition]);
	}

	return bytesRead;
}
