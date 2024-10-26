#include <stdio.h>

int n, m;

int a[1000001], b[1000001];
int result[2000002];

int main()
{
    scanf("%d %d", &n, &m);

    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }

    for (int i = 0; i < m; i++)
    {
        scanf("%d", &b[i]);
    }

    int aIdx = 0;
    int bIdx = 0;

    for (int i = 0; i < n + m; i++)
    {
        if (bIdx == m)
        {
            result[i] = a[aIdx++];
        }
        else if (aIdx == n)
        {
            result[i] = b[bIdx++];
        }
        else if (a[aIdx] <= b[bIdx])
        {
            result[i] = a[aIdx++];
        }
        else
        {
            result[i] = b[bIdx++];
        }
    }

    for (int i = 0; i < n + m; i++)
    {
        printf("%d ", result[i]);
    }
    printf("\n");
    return 0;
}
