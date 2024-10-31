#include <stdio.h>

int n, m, startX, startY;
int map[1000][1000];
int visit[1000][1000];
int distance[1000][1000];

int move_x[4] = {1, -1, 0, 0};
int move_y[4] = {0, 0, 1, -1};

typedef struct pos
{
    int x;
    int y;
} pos;
int front = 0, rear = 0;

pos position[10000001];

void bfs()
{
    while (front < rear)
    {
        int currX = position[front].x;
        int currY = position[front++].y;
        for (int i = 0; i < 4; i++)
        {
            int newX = currX + move_x[i];
            int newY = currY + move_y[i];
            if (newX >= 0 && newX < n && newY >= 0 && newY < m && visit[newX][newY] == 0 && map[newX][newY] == 1)
            {
                visit[newX][newY] = 1;
                distance[newX][newY] = distance[currX][currY] + 1;
                position[rear].x = newX;
                position[rear++].y = newY;
            }
        }
    }
    return;
}

int main()
{
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            scanf("%d", &map[i][j]);
            if (map[i][j] == 2)
            {
                startX = i;
                startY = j;
                visit[i][j] = 1;
                distance[i][j] = 0;
                position[rear].x = i;
                position[rear++].y = j;
            }
        }
    }

    bfs();

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (map[i][j] == 1 && visit[i][j] == 0)
                printf("-1 ");
            else
                printf("%d ", distance[i][j]);
        }
        printf("\n");
    }
    return 0;
}