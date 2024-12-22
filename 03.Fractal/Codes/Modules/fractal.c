#include "image.h"
#include "fractal.h"
#include <math.h>

# define max_level 7
# define black_color 0
# define white_color 255
# define coef sqrt(3)

int pow_func(int m, int n) {
    int result = 1;
    for (int i=0; i<n; i++) {
        result *= m;
    }
    return result;
}

void draw_carpet(image_p picture, int x_min, int y_min, int x_max, int y_max) {
    for (int x = x_min; x < x_max; x++) {
        for (int y = y_min; y < y_max; y++) {
            set_pixel(picture, x, y, black_color);
        }
    }
}

void carpet(image_p picture, int level, int limit_level, int x_min, int y_min) {
    if (level > limit_level) {
        return;
    }
    int new_x_min, new_y_min, new_x_max, new_y_max;
    for (int row=0; row<3; row++) {
        new_y_min = y_min + pow_func(3, max_level - level) * (row + 0);
        new_y_max = y_min + pow_func(3, max_level - level) * (row + 1);
        for (int column=0; column<3; column++) {
            new_x_min = x_min + pow_func(3, max_level - level) * (column + 0);
            new_x_max = x_min + pow_func(3, max_level - level) * (column + 1);
            if ((row == 1) && (column == 1)) {
                draw_carpet(picture, new_x_min, new_y_min, new_x_max, new_y_max);
            } else {
                carpet(picture, level+1, limit_level, new_x_min, new_y_min);
            }
        }
    }
}

void draw_triangle(image_p picture, int size) {
    int x_mid = (size - size % 2) / 2, h = size / 2 * coef, y_max;
    for (int x=0; x<size; x++) {
        if (x <= x_mid) {
            y_max = coef * x + 1;
        } else {
            y_max = h - coef * (x - x_mid) + 1;
        }
        for (int y=0; y<y_max; y++) {
            set_pixel(picture, x, y, black_color);
        }
    }
}

void draw_inverted_triangle(image_p picture, int x_start, int y_start, int x_mid, int h) {
    int y_max;
    for (int x=x_start; x<=x_start+x_mid; x++) {
        if (x <= x_mid) {
            y_max = h - coef * (x - x_start) + 2;
            y_max *= (y_max >= 0);
        } else {
            y_max = coef * (x - x_mid) + 2;
        }
        for (int y=h+y_start; y>y_max+y_start; y--) {
            set_pixel(picture, x, y, white_color);
        }
    }
}

void triangle(image_p picture, int level, int limit_level, int x_min, int y_min, int size) {
    if (level >= limit_level) {
        return;
    }
    int x_part, x_mid, h;
    x_part = (size - size % 4) / 4;
    x_mid = (size - size % 2) / 2;
    h = x_part * coef;
    draw_inverted_triangle(picture, x_min+x_part, y_min, x_min+x_mid, h);
    triangle(picture, level+1, limit_level, x_min, y_min, x_mid);
    triangle(picture, level+1, limit_level, x_min+x_mid, y_min, x_mid);
    triangle(picture, level+1, limit_level, x_min+x_part, y_min+h, x_mid);
}

void draw_inverted_image(image_p picture, int size) {
    int color_1, color_2;
    for (int x=0; x<size; x++) {
        for (int y=0; y<size/2; y++) {
            color_1 = get_pixel(picture, x, y);
            color_2 = get_pixel(picture, x, size - y - 1);
            set_pixel(picture, x, y, color_2);
            set_pixel(picture, x, size - y - 1, color_1);
        }
    }
}

void create_empty_fractal(image_p picture, int size) {
    for (int x=0; x<size; x++) {
        for (int y=0; y<size; y++) {
            set_pixel(picture, x, y, white_color);
        }
    }
}

void empty_fractal(int flag, int limit_level)
{
    int level = 1, size;
    size = pow_func(3, max_level);
    image_p picture_fractal = create_image(size, size);
    create_empty_fractal(picture_fractal, size);
    if (flag == 1) {
        carpet(picture_fractal, level, limit_level, 0, 0);
    } else {
        draw_triangle(picture_fractal, size);
        triangle(picture_fractal, level, limit_level, 0, 0, size);
        draw_inverted_image(picture_fractal, size);
    }
    save_pgm(picture_fractal, "fractal.pgm");
    free_image(picture_fractal);
}
