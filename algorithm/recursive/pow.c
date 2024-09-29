#include <stdio.h>

long long POW(long long a, long long b, long long c)
{
    if (b == 1)
        return a % c;
    long long val = POW(a, b / 2, c);

    val = val * val % c;

    if (b % 2 == 0)
        return val;
    return val * a % c;
}

int main()
{
    int a, b, c;
    scanf("%d %d %d", &a, &b, &c);

    printf("%lld\n", POW(a, b, c));

    return 0;
}