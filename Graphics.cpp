// 
// 
// 

#include "Graphics.h"

Graphics::Graphics(uint8_t sdaPin, uint8_t sclPin)
{
	this->displayController = new IIC_without_ACK(sdaPin, sclPin);
	this->displayController->Initial();
}

void Graphics::Draw_Xbm(unsigned char x0, unsigned char y0, unsigned char x1, unsigned char y1, const char xbm[]) {

}

