#include <stdio.h>
#include <stdlib.h>

int arr[9][9];

int check(int x, int y, int n)
{
    for (int i = 0; i < 9; i++)
    {
        if (arr[x][i] == n || arr[i][y] == n)
        {
            return 0;
        }
    }

    int nx = x / 3 * 3;
    int ny = y / 3 * 3;

    for (int i = nx; i < nx + 3; i++)
    {
        for (int j = ny; j < ny + 3; j++)
        {
            if (n == arr[i][j])
                return 0;
        }
    }
    return 1;
}

void dfs(int x, int y)
{
    if (y == 9)
    {
        x++;
        y = 0;
    }

    if (x == 9)
    {
        for (int i = 0; i < 9; i++)
        {
            for (int j = 0; j < 9; j++)
            {
                printf("%d ", arr[i][j]);
            }
            printf("\n");
        }
        exit(0);
    }

    if (arr[x][y] == 0)
    {
        for (int i = 1; i <= 9; i++)
        {
            if (check(x, y, i))
            {
                arr[x][y] = i;
                dfs(x, y + 1);
                arr[x][y] = 0;
            }
        }
    }
    else
        dfs(x, y + 1);
    return;
}

int main()
{
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            scanf("%d", &arr[i][j]);
        }
    }

    dfs(0, 0);
    return 0;
}