// Graphics.h
#ifndef _GRAPHICS_h
#define _GRAPHICS_h

#ifndef SCREEN_WIDTH
#define SCREEN_WIDTH 128
#endif

#ifndef SCREEN_HEIGHT
#define SCREEN_HEIGHT 64
#endif

#include <IIC_without_ACK.h>
#include "XbmImage.h"

#if defined(ARDUINO) && ARDUINO >= 100
#include "arduino.h"
#else
#include "WProgram.h"
#endif

enum TextSize { s6x8, s8x16 };

class Graphics {
public:
	Graphics(uint8_t sdaPin, uint8_t sclPin);
	uint8_t GetWidth();
	uint8_t GetHeight();
	void Draw_Xbm(unsigned char x0, unsigned char y0, XbmImage & image);
	void Print(const char text[], TextSize size, unsigned char x, unsigned char y);
	void Clear();
private:
	IIC_without_ACK *displayController;
};
#endif