#include <stdio.h>
#include <limits.h>
#include <stdlib.h>

int N;
int arr[21][21];
int isUsed[21];
int min = INT_MAX;
int max_start = -1;

void func(int count)
{
    if (count == N / 2)
    {
        int start[N / 2];
        int link[N / 2];
        int start_count = 0, link_count = 0;
        for (int i = 0; i < N; i++)
        {
            if (isUsed[i] == 1)
            {
                start[start_count] = i;
                start_count++;
            }
            else
            {
                link[link_count] = i;
                link_count++;
            }
        }

        int start_sum = 0;
        int link_sum = 0;
        for (int i = 0; i < N / 2; i++)
        {
            for (int j = 0; j < N / 2; j++)
            {
                start_sum += arr[start[i]][start[j]];
                link_sum += arr[link[i]][link[j]];
            }
        }

        int diff = abs(start_sum - link_sum);
        if (diff < min)
            min = diff;
    }
    else
    {
        if (count == 0)
        {
            isUsed[0] = 1;
            max_start = 0;
            func(count + 1);
        }
        else
        {
            for (int i = 1; i < N; i++)
            {
                if (isUsed[i] == 0 && i > max_start)
                {
                    isUsed[i] = 1;
                    int old_max = max_start;
                    max_start = i;
                    func(count + 1);
                    isUsed[i] = 0;
                    max_start = old_max;
                }
            }
        }
    }
}

int main()
{
    scanf("%d", &N);

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            scanf("%d", &arr[i][j]);
        }
    }

    func(0);

    printf("%d", min);

    return 0;
}