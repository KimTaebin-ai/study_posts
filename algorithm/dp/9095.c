#include <stdio.h>

int d[12];

int main()
{
    int n;

    scanf("%d", &n);

    d[1] = 1;
    d[2] = 2;
    d[3] = 4;

    for (int i = 4; i < 11; i++)
    {
        d[i] = d[i - 1] + d[i - 2] + d[i - 3];
    }

    int t;
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &t);
        printf("%d\n", d[t]);
    }

    return 0;
}