/*
 *   Test:
 *     test complicated branch conditions.
 *      */

#include "stdio.h"
#include "stdint.h"
#include "stdlib.h"
#include "string.h"

#include "../Int.h"

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

    Int ans = 1;
    Int tmp = x;
    for (int i = 0; i < 20; i++)
    {
        ans = ans - x + x / 4 * 5;
        x = x / 2;
    }

    if (ans < 10000 && tmp > 12000)
    {
        abort();
    }

    return 0;
}
