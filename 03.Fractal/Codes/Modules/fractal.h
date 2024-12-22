#ifndef _FRACTAL_H_
#define _FRACTAL_H_

#include "image.h"

/**
 * @brief Draws empty fractal, assuming image is clean
 *
 * @param picture 
 */
void empty_fractal(int flag, int limit_level);

void carpet(image_p picture, int level, int limit_level, int x_min, int y_min);

void draw_carpet(image_p picture, int x_min, int y_min, int x_max, int y_max);

int pow_func(int m, int n);

void create_empty_fractal(image_p picture, int size);

#endif // _FRACTAL_H_
