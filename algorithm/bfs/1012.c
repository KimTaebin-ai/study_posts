#include <stdio.h>
#include <memory.h>

int arr[55][55] = {0};

int dx[4] = {0, 0, -1, 1};
int dy[4] = {1, -1, 0, 0};

int t, m, n, k;

int a, b;

int ans;

void dfs(int x, int y)
{
    for (int i = 0; i < 4; i++)
    {
        int X = x + dx[i];
        int Y = y + dy[i];

        if (X >= 0 && X < n && Y >= 0 && Y < m && arr[X][Y] == 1)
        {
            arr[X][Y] = 0;
            dfs(X, Y);
        }
    }

    return;
}

int main()
{
    scanf("%d", &t);

    while (t--)
    {
        ans = 0;

        scanf("%d %d %d", &m, &n, &k);

        for (int i = 0; i < n; i++)
            memset(arr[i], 0, m * sizeof(int));

        for (int i = 0; i < k; i++)
        {
            scanf("%d %d", &a, &b);
            arr[b][a] = 1;
        }

        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                if (arr[i][j] == 1)
                {
                    dfs(i, j);
                    ans++;
                }

        printf("%d\n", ans);
    }

    return 0;
}