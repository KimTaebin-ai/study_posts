#include <stdio.h>

long long total, mid, n, m, result, max = 0;

void binary_search(long long arr[n], int left, int right)
{
    if (left > right)
        return;
    total = 0;
    mid = (left + right) / 2;

    for (int i = 0; i < n; i++)
    {
        if (arr[i] > mid)
            total += arr[i] - mid;
    }

    if (total < m)
        binary_search(arr, left, mid - 1);

    else
    {
        result = mid;
        binary_search(arr, mid + 1, right);
    }
}

int main(void)
{
    scanf("%lld %lld", &n, &m);
    long long trees[n];

    for (int i = 0; i < n; i++)
    {
        scanf("%lld", &trees[i]);
        if (max < trees[i])
            max = trees[i];
    }
    binary_search(trees, 0, max);
    printf("%lld", result);
    return (0);
}