#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[])
{
     puts("STDOUT\n");
     fputs("STDERR\n", stderr);
     return 0;
}
