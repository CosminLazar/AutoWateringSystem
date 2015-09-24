#include "Graphics.h"

Graphics::Graphics(uint8_t sdaPin, uint8_t sclPin)
{
	this->displayController = new IIC_without_ACK(sdaPin, sclPin);
	this->displayController->Initial();
}

uint8_t Graphics::GetWidth()
{
	return SCREEN_WIDTH;
}

uint8_t Graphics::GetHeight()
{
	return SCREEN_HEIGHT;
}

void Graphics::Draw_Xbm(unsigned char x, unsigned char y, XbmImage & image)
{
	//validate y, height, width % 8

	//the buffer must fit at least one full line on the screen
	const uint8_t bufferSize = SCREEN_WIDTH;
	uint8_t buffer[bufferSize];
	ResourceStreamer streamer = image.GetStream();

	uint8_t noOfLines = image.GetHeight() / 8;
	uint8_t rightMostX = x + image.GetWidth();
	uint8_t bytesPerLine = image.GetWidth();
	uint8_t noOfLinesFittingInBuffer = bufferSize / bytesPerLine;


	for (uint8_t sliceYPosition = 0; sliceYPosition < noOfLines; sliceYPosition += noOfLinesFittingInBuffer) {
		uint8_t bytesRead = streamer.ReadNext(buffer, bufferSize);
		uint8_t linesRead = bytesRead / bytesPerLine;

		this->displayController->Draw_BMP(x, y + sliceYPosition, rightMostX, y + sliceYPosition + linesRead, (char *)buffer);
	}
}

void Graphics::Print(const char text[], TextSize size, unsigned char x, unsigned char y)
{
	switch (size)
	{
	case s6x8:
		this->displayController->Char_F6x8(x, y, text);
		break;
	case s8x16:
		this->displayController->Char_F8x16(x, y, text);
		break;
	default:
		this->displayController->Char_F6x8(x, y, text);
		break;
	}
}

void Graphics::Clear()
{
	this->displayController->Fill_Screen(BLACK);
}
