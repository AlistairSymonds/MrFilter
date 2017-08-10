#include "FIlterUtil.h"
#include "Filters.h"
#include <cstdint>


void average(img32d *input, img32d *output) {
	for (int y = 1; y < input->h-1; y++) {
		for (int x = 1; x < input->w-1; x++) {
			
			for (int c = 0; c < 4; c++) {
			}

			
		}
	}
		
	
	/*
	a = a / 9;
	r = r / 9;
	g = g / 9;
	b = b / 9;

	output->a[y*img->w + x] = (uint8_t)a;
	output->r[y*img->w + x] = (uint8_t)r;
	output->g[y*img->w + x] = (uint8_t)g;
	output->b[y*img->w + x] = (uint8_t)b;
	*/
}

void average(uint8_t *inChannel, uint8_t *outChannel, int pixelCount) {
	
	
}

uint8_t averageChannel(uint8_t *in, int stride) {
	int level = 0;
	for (int i = -1; i < 2; i++) {
		for (int j = -i; j < 2; j++) {
			level += in[(y*stride) + x];
		}
	}
}

void averageAVX(img32d *img, img32d *output, int x, int y) {

}