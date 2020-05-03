/*
 *   Test:
 *     test complicated branch conditions.
 *      */

#include "stdio.h"
#include "stdint.h"
#include "stdlib.h"
#include "string.h"

#include "../Int.h"


Int  __attribute__ ((noinline))  foo(Int x, Int y) {
    return x * y + 123 * x * y * y - 321 * y;
}


int main (int argc, char** argv) {
    if (argc < 2) return 0;

    FILE *fp;
    size_t ret;

    fp = fopen(argv[1], "rb");

    if (!fp) {
          printf("st err\n");
            return 0;
    }

    int len = 1;
    int16_t _x = 0;
    ret = fread(&_x, sizeof _x, 1, fp);
    Int x = Int(_x, 1);
    x.get_dx(-1);
    fclose(fp);
    if (ret < len) {
          printf("input fail \n");
            return 0;
    }

    Int d = x + 10;
    if (d * d < 1000)
    {
        if (foo(d, 100 / (x + 3)) < 125963 
            && foo(d, 100 / (x + 3)) > 120000)  {
            abort();
        }
    }

    return 0;
}
