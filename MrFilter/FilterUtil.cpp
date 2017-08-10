#include <windows.h>
#include "FIlterUtil.h"
#include <stdio.h>
#include <gdiplus.h>
#pragma comment (lib, "Gdiplus.lib")
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
	BitmapData bitmapData;
	bmp->LockBits(&Rect(0, 0, bmp->GetWidth(), bmp->GetHeight()), ImageLockModeWrite, PixelFormat32bppARGB, &bitmapData);
	uint8_t *rawData = (uint8_t*) bitmapData.Scan0;
	img = (img32d*) malloc(sizeof(img32d));
	img->h = bmp->GetHeight();
	img->w = bmp->GetWidth();
	img->padAmt = 0;
	size_t numPixels = img->h*img->w;
	img->pixels[alpha] = (uint8_t*)malloc(numPixels);
	img->pixels[red] = (uint8_t*)malloc(numPixels);
	img->pixels[green] = (uint8_t*)malloc(numPixels);
	img->pixels[blue] = (uint8_t*)malloc(numPixels);

	for (int i = 0; i < numPixels; i++) {
		img->pixels[alpha][i] = rawData[(i*4)];
		img->pixels[red][i] = rawData[(i * 4)+1];
		img->pixels[green][i] = rawData[(i * 4)+2];
		img->pixels[blue][i] = rawData[(i * 4)+3];
	}
}

void img32d2gdiplusbmp(img32d *img, Bitmap* bmp) {
	size_t numPixels = img->w*img->h;
	uint8_t *pixels = (uint8_t*) malloc(numPixels * 4);
	int pos = 0;
	for (int y = 0; y < img->h; y++) {
		for (int x = 0; x < img->w; x++) {
			pixels[pos] = img->pixels[alpha][y][x];
			pixels[(pos * 4) + 1] = img->pixels[red][y][x];
			pixels[(pos * 4) + 2] = img->pixels[green][y][x];
			pixels[(pos * 4) + 3] = img->pixels[blue][y][x];
			pos++;
		}
		
	}
	bmp = new Bitmap(img->w, img->h, 4 * img->w, PixelFormat32bppARGB, pixels);
}

void freeimg32d(img32d *img) {
	for (int i = 0; i < 4; i++) {

	}
}
