#include <stdio.h>
#include <time.h>

void calculate_pi()
{
    int r[2800 + 1];
    int i, k;
    int b, d;
    int c = 0;

    for (i = 0; i < 2800; i++)
    {
        r[i] = 2000;
    }

    for (k = 2800; k > 0; k -= 14)
    {
        d = 0;

        i = k;
        for (;;)
        {
            d += r[i] * 10000;
            b = 2 * i - 1;

            r[i] = d % b;
            d /= b;
            i--;
            if (i == 0)
                break;
            d *= i;
        }
        printf("%.4d", c + d / 10000);
        c = d % 10000;
    }
}

int main()
{
    // start timing
    clock_t start = clock(), diff;

    calculate_pi();

    // end of timing
    diff = clock() - start;
    int msec = diff * 1000 / CLOCKS_PER_SEC;
    printf("Time taken %d seconds %d milliseconds", msec / 1000, msec % 1000);

    return 0;
}