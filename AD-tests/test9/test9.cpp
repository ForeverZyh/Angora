/*
 *   Test:
 *     test complicated branch conditions.
 *      */

#include "stdio.h"
#include "stdint.h"
#include "stdlib.h"
#include "string.h"

#include "../Int.h"

Int  __attribute__ ((noinline))  foo(Int y) {
    return y * 24 - 222 + y / 100 + 123456 / y;
}

Int  __attribute__ ((noinline))  bar(Int y) {
    return foo(y * 35 - 444 + y / 10 + 654321 / y);
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
    // foo(12345) = 296191
    // bar(12345) = foo(432918) = 10394139
    Int tmp = bar(d);
    Int t1 = foo(x);
    if (tmp < 11000000 && t1 * 36 > tmp && t1 * 35 + 20000 < tmp && t1 > 290000)
    {    
        abort();
    }

    return 0;
}
