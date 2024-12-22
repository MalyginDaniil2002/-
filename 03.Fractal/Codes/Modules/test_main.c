#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include "image.h"
#include "fractal.h"
#include "../Test_modules/utest.h"

struct ImageTestFixture {
    image_p i;
};

UTEST_F_SETUP(ImageTestFixture) {
    utest_fixture->i = create_image(300, 300);
    ASSERT_NE((void *) utest_fixture->i, NULL);
}

UTEST_F_TEARDOWN(ImageTestFixture) {
    free_image(utest_fixture->i);
}

UTEST_F(ImageTestFixture, Set_Get_Pixel1) {
    set_pixel(utest_fixture->i, 10, 10, 10);
    ASSERT_EQ(10, get_pixel(utest_fixture->i, 10, 10));
}

UTEST_F(ImageTestFixture, ClearImage2) {
    clear_image(utest_fixture->i);
    ASSERT_EQ(0, get_pixel(utest_fixture->i, 10, 10));
}

UTEST_F(ImageTestFixture, FractalFile) {
    empty_fractal(2, 7);
    FILE *file = fopen("fractal.pgm", "r");
    bool is_exist = false;
    if (file != NULL)
    {
        is_exist = true;
        fclose(file);
    }
    ASSERT_TRUE(is_exist);
}

bool picture_check(int flag, int limit_level) {
    int max_level = 7, level = 1, size;
    size = pow_func(3, max_level);
    image_p picture = create_image(size, size);
    create_empty_fractal(picture, size);
    if (flag == 1) {
        carpet(picture, level, limit_level, 0, 0);
    } else {
        draw_triangle(picture, size);
        triangle(picture, level, limit_level, 0, 0, size);
        change_vertical(picture, size, size * (1 - sqrt(3) / 2) / 2);
        draw_inverted_image(picture, size);
    }
    char tmp[4];
    char fractal_string[size][size];
    for (int y=0; y<size; y++) {
        for (int x=0; x<size; x++) {
            sprintf(tmp, "%c", get_pixel(picture, x, y));
            if (x != size - 1) {
                tmp[3] = ' ';
            } else {
                tmp[3] = '\n';
            }
            strcat(fractal_string[y], tmp);
        }
    }
    empty_fractal(flag, limit_level);
    bool is_identical = true;
    char file_string[5*size];
    FILE *file = fopen("fractal.pgm", "r");
    int i = 0, count = 3;
    while (fgets(file_string, 4*count, file) != NULL) {
        if (count != 0) {
            count -= 1;
            continue;
        }  
        is_identical = is_identical && (strcmp(fractal_string[i], file_string) == 0);
        i += 1;
    }
    fclose(file);
    free_image(picture);
    return is_identical;
}

UTEST_F(ImageTestFixture, Fractal) {
    ASSERT_TRUE(picture_check(2, 5));
}

UTEST_MAIN();
