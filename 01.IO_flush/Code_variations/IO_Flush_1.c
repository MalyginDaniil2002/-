#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[])
{
     puts("STDOUT");
     fflush(stdout);
     fputs("STDERR", stderr);
     fflush(stderr);
     return 0;
}
