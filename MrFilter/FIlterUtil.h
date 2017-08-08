#pragma once
#ifndef FILTER_UTIL
#define FILTER_UTIL
#endif // !1
#include <cstdint>



void padImage(unsigned int *original, unsigned int *padded, int h, int w, int padAmt);
int getPaddedPixelCount(int height, int width, int padCount);
int origPos2padPos(int padAmt, int origX, int origY, int origH, int origW);
typedef struct img32d {
	int w;
	int h;
	int padAmt;
	uint8_t *a;
	uint8_t *r;
	uint8_t *g;
	uint8_t *b;
}img32d;