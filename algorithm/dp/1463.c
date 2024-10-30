#include <stdio.h>

#define min(x, y) (x) < (y) ? (x) : (y)

int d[1000005];
int n;

int main()
{
    scanf("%d", &n);
    d[1] = 0;
    for (int i = 2; i <= n; i++)
    {
        d[i] = d[i - 1] + 1;
        if (i % 2 == 0)
        {
            d[i] = min(d[i], d[i / 2] + 1);
        }

        if (i % 3 == 0)
        {
            d[i] = min(d[i], d[i / 3] + 1);
        }
    }

    printf("%d", d[n]);
    return 0;
}