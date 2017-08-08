#include "FIlterUtil.h"
#include <stdio.h>
#include <gdiplus.h>
using namespace Gdiplus;

void padImage(unsigned int *original, unsigned int *padded, int h, int w, int padAmt) {
	int paddedLineLength = w + (2 * padAmt);
	int topOffset = (padAmt * paddedLineLength);
	for (int i = 0; i < h; i++) {
		int leftOffset = topOffset + (i * paddedLineLength) + padAmt;
		for (int j = 0; j < w; j++) {
			
			padded[leftOffset+j] = original[(i*w) + j];
		}
	}
}

int getPaddedPixelCount(int height, int width, int padCount) {
	return (height + (padCount * 2))*(width + (padCount * 2));
}

int origPos2padPos(int padAmt, int origX, int origY, int origH, int origW) {
	int paddedLineLength = origW + (2 * padAmt);
	int topOffset = (padAmt * paddedLineLength);
	int leftOffset = topOffset + (origY * paddedLineLength) + padAmt;
	return leftOffset + origX;
}

void gdiplus2img32d(Bitmap *bmp, img32d *img) {

}

void freeimg32d(img32d *img) {

}
