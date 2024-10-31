#include <stdio.h>
#include <stdlib.h>

typedef struct _Queue
{
    int x;
    int y;
    int order; // 익는 차례
} Queue;

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int N, M;
int front, rear;

void BFS(int **box, Queue *q, int y, int x)
{
    while (front < rear)
    {
        front++;
        for (int i = 0; i < 4; i++)
        {
            int ny = q[front].y + dy[i];
            int nx = q[front].x + dx[i];
            if (ny < 0 || nx < 0 || ny >= N || nx >= M)
                continue;
            else
            {
                if (!box[ny][nx])
                {
                    rear++;
                    q[rear].y = ny;
                    q[rear].x = nx;
                    q[rear].order = q[front].order + 1;
                    box[ny][nx] = 1;
                }
            }
        }
    }
}

int main()
{
    int i, j;
    scanf("%d %d", &M, &N);

    int **box = (int **)calloc(N, sizeof(int *));

    for (i = 0; i < N; i++)
        box[i] = (int *)calloc(M, sizeof(int));

    int total = N * M;

    Queue *q = (Queue *)calloc(N * M + 1, sizeof(Queue));

    front = 0, rear = 0;

    for (i = 0; i < N; i++)
    {
        for (j = 0; j < M; j++)
        {
            scanf("%d", &box[i][j]);
            if (box[i][j] == -1)
                total--;
            else if (box[i][j])
            {
                rear++;
                q[rear].y = i;
                q[rear].x = j;
                q[rear].order = 0;
            }
        }
    }

    BFS(box, q, q[0].y, q[0].x);

    if (total != rear)
        printf("-1");
    else
        printf("%d", q[rear].order);

    for (i = 0; i < N; i++)
        free(box[i]);
    free(box);

    return 0;
}