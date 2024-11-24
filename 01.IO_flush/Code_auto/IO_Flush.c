#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[])
{
    int variation = atoi(argv[1]);
    if (variation == 1) {
        puts("STDOUT");
        fflush(stdout);
        fputs("STDERR", stderr);
        fflush(stderr);
    } else if (variation == 2) {
        puts("STDOUT\n");
        fflush(stdout);
        fputs("STDERR\n", stderr);
        fflush(stderr);
    } else if (variation == 3) {
        puts("STDOUT");
        fputs("STDERR", stderr);
    } else {
        puts("STDOUT\n");
        fputs("STDERR\n", stderr);
    }
    return 0;
}
