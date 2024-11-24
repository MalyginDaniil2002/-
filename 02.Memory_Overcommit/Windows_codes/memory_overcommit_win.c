#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

typedef unsigned long long type_size;
typedef long double type_array;
#define INTERVAL 0.8
#define LIMIT 2560

int get_data(char *argv[], type_size* size, int* flag) {
    *size = atoi(argv[1]);
    *flag = atoi(argv[2]);
}

void overcommit(type_array *array, type_size size, int flag) {
    type_size step = 4*1024/sizeof(array[0]);
    type_array summa = 0;
    type_size index = step;
    while ((index < size) && (index > 0)) {
        if (flag == 0)
            summa += array[index];
        else
            array[index] = index;
        if ((index / step) % LIMIT == 0) {
            Sleep(INTERVAL);
        }
        index += step;
    }
}

int main(int argc, char* argv[]) {
    int flag;
    printf("\n%c\n", argv[2]);
    type_size size = 1;
    size, flag = get_data(argv, &size, &flag);
    printf("size = %llu, flag = %i\n", size, flag);
    type_array *array = malloc(sizeof(type_array)*size);
    overcommit(array, size, flag);
    printf("STOP!!!\n");
    free(array);
    return 0;
}