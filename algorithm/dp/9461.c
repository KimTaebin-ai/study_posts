#include <stdio.h>

int main()
{
    int n, i, buf;
    long long dp[101] = {0, 1, 1, 1};

    for (i = 4; i < 101; i++)
        dp[i] = dp[i - 2] + dp[i - 3];

    scanf("%d", &n);

    for (i = 0; i < n; i++)
    {
        scanf("%d", &buf);
        printf("%lld\n", dp[buf]);
    }

    return 0;
}