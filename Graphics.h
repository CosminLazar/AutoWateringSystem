// Graphics.h
#ifndef _GRAPHICS_h
#define _GRAPHICS_h

#include <IIC_without_ACK.h>

#if defined(ARDUINO) && ARDUINO >= 100
#include "arduino.h"
#else
#include "WProgram.h"
#endif


class Graphics {
public:
	Graphics(uint8_t sdaPin, uint8_t sclPin);
	void Draw_Xbm(unsigned char x0, unsigned char y0, unsigned char x1, unsigned char y1, const char xbm[]);

private:
	IIC_without_ACK *displayController;
};
#endif