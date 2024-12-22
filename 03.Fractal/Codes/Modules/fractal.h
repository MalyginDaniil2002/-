#ifndef _FRACTAL_H_
#define _FRACTAL_H_

#include "image.h"

/**
 * @brief Draws empty fractal, assuming image is clean
 *
 * @param picture 
 */
void empty_fractal(int flag, int limit_level);

int pow_func(int m, int n);

void carpet(image_p picture, int level, int limit_level, int x_min, int y_min);

void draw_triangle(image_p picture, int size);

void triangle(image_p picture, int level, int limit_level, int x_min, int y_min, int size);

void change_vertical(image_p picture, int size, int h);

void draw_inverted_image(image_p picture, int size);

void create_empty_fractal(image_p picture, int size);

#endif // _FRACTAL_H_
