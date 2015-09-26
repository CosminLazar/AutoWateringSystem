// Image credit
// Icon made by Freepik (http://www.freepik.com) from www.flaticon.com is licensed under CC BY 3.0
// Link: http://www.flaticon.com/free-icon/watering-can-with-water-drops_67739

#include "WateringCanImg.h"

const PROGMEM uint8_t imageData[] = { 0x40,0xF8,0xFC,0x0E,0x06,0x03,0x03,0x83,0xC3,0xE7,0xFE,0xFC,0xFC,0xFC,0xFC,0xF8,0xF0,0xE0,0xC0,0x80,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x03,0x3F,0x7E,0xFE,0xFE,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xBF,0x9F,0x87,0x82,0x80,0xC0,0xC0,0xC0,0xF0,0xF8,0xF8,0x80,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x01,0x03,0x03,0x07,0x0F,0x1F,0x1F,0x1F,0x0F,0x07,0x03,0x03,0x03,0x03,0x03,0x03,0x03,0x01,0x01,0x01,0x01,0x03,0x07,0x07,0xC7,0xE0,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x60,0xF0,0xE0,0x01,0x01,0x00 };

uint8_t WateringCanImg::GetWidth()
{
	return 32;
}

uint8_t WateringCanImg::GetHeight()
{
	return 32;
}

ResourceStreamer WateringCanImg::GetStream()
{
	return ResourceStreamer(imageData, sizeof(imageData));
}
