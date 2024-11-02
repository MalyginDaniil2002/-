#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[])
{
     puts("STDOUT");
     fputs("STDERR", stderr);
     return 0;
}
