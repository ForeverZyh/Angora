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
    return y - y / 9 + 103041 / y;
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

    Int ans = x;
    Int pre = x;
    for (int i = 0; i < 5; i++)
    {
        pre = ans;
        ans = foo(ans);
	//printf("%lld\n", ans.get_dx(0));
    }

    Int t = ans - foo(ans);
    //printf("%lld\n", t.get_dx(1));
    if (x < 10000 && ans == foo(ans))
    {
        abort();
    }

    return 0;
}
