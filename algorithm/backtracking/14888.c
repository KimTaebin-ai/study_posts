#include <stdio.h>
#include <limits.h>

int N;

int arr[12];

int plus, minus, multi, div;

int max = INT_MIN;
int min = INT_MAX;

void func(int k, int sum)
{
    // 기저조건
    if (k == N - 1)
    {
        if (max < sum)
        {
            max = sum;
        }

        if (min > sum)
        {
            min = sum;
        }
    }

    if (plus > 0)
    {
        plus--;
        func(k + 1, sum + arr[k + 1]);
        plus++;
    }

    if (minus > 0)
    {
        minus--;
        func(k + 1, sum - arr[k + 1]);
        minus++;
    }

    if (multi > 0)
    {
        multi--;
        func(k + 1, sum * arr[k + 1]);
        multi++;
    }

    if (div > 0)
    {
        div--;
        func(k + 1, sum / arr[k + 1]);
        div++;
    }
}

int main()
{
    scanf("%d", &N);
    for (int i = 0; i < N; i++)
    {
        scanf("%d ", &arr[i]);
    }

    scanf("%d %d %d %d", &plus, &minus, &multi, &div);
    func(0, arr[0]);
    printf("%d\n%d", max, min);
    return 0;
}