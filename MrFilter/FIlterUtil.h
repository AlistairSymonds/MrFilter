#pragma once
#ifndef FILTER_UTIL
#define FILTER_UTIL
#endif // !1
#include<Windows.h>
#include <cstdint>
#include <gdiplus.h>
#pragma comment (lib, "Gdiplus.lib")

enum channel {alpha, red, green, blue};


void padImage(unsigned int *original, unsigned int *padded, int h, int w, int padAmt);
int getPaddedPixelCount(int height, int width, int padCount);
int origPos2padPos(int padAmt, int origX, int origY, int origH, int origW);


typedef struct img32d {
	int w;
	int h;
	int padAmt;
	uint8_t *pixels[4];
}img32d;

void img32d2gdiplusbmp(img32d *img, Gdiplus::Bitmap* bmp);
void gdiplus2img32d(Gdiplus::Bitmap *bmp, img32d *img);