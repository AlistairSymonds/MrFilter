#include "FIlterUtil.h"
#include "Filters.h"
#include <cstdint>


void average(img32d *img, img32d *output, int x, int y) {
	int a = 0;
	int r = 0;
	int g = 0;
	int b = 0;
	for (int i = -1; i < 2; i++) {
		for (int j = -i; j < 2; j++) {
			a += img->a[y*img->w + x];
			r += img->r[y*img->w + x];
			g += img->g[y*img->w + x];
			b += img->b[y*img->w + x];
		}
	}
	a = a / 9;
	r = r / 9;
	g = g / 9;
	b = b / 9;

	output->a[y*img->w + x] = (uint8_t)a;
	output->r[y*img->w + x] = (uint8_t)r;
	output->g[y*img->w + x] = (uint8_t)g;
	output->b[y*img->w + x] = (uint8_t)b;
}
void averageAVX(img32d *img, img32d *output, int x, int y) {

}