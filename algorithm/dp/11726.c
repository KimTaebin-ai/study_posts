#include <stdio.h>

int d[1001];

int main()
{
    int N;
    int i;
    d[0] = d[1] = 1;
    scanf("%d", &N);
    for (i = 2; i <= N; i++)
    {
        d[i] = (d[i - 1] + d[i - 2]) % 10007;
    }
    printf("%d", d[N]);

    return 0;
}
