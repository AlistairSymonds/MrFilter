#ifndef FILTERS_H
#define FILTERS_H
#endif // !FILTERS_H

#pragma once
#include "FIlterUtil.h"
void average(img32d *img, img32d *output, int x, int y);
void averageAVX(img32d *img, img32d *output, int x, int y);