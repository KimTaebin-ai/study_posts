#include <stdio.h>

int N, M;
int board[101][101];
int dist[101][101];

typedef struct
{
    int x;
    int y;
} LocationPoint;

typedef struct
{
    LocationPoint data[101 * 101];
    int head;
    int tail;
} Queue;

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

void initQueue(Queue *q)
{
    q->head = 0;
    q->tail = 0;
}

void push(Queue *q, LocationPoint p)
{
    q->data[q->tail++] = p;
}

LocationPoint pop(Queue *q)
{
    return q->data[q->head++];
}

int empty(Queue *q)
{
    return q->head == q->tail;
}

int main()
{
    Queue Q;
    initQueue(&Q);

    scanf("%d %d", &N, &M);

    char line[102]; // 줄바꿈 문자를 고려하여 크기 설정
    for (int i = 0; i < N; i++)
    {
        scanf("%s", line);
        for (int j = 0; j < M; j++)
        {
            board[i][j] = line[j] - '0'; // 문자를 숫자로 변환
            dist[i][j] = -1;
        }
    }

    push(&Q, (LocationPoint){0, 0});
    dist[0][0] = 1;

    while (!empty(&Q))
    {
        LocationPoint current = pop(&Q);

        if (current.x == N - 1 && current.y == M - 1)
        {
            printf("%d\n", dist[N - 1][M - 1]);
            return 0;
        }

        for (int dir = 0; dir < 4; dir++)
        {
            int nX = current.x + dx[dir];
            int nY = current.y + dy[dir];

            if (nX < 0 || nX >= N || nY < 0 || nY >= M)
                continue;
            if (dist[nX][nY] >= 0 || board[nX][nY] != 1)
                continue;

            dist[nX][nY] = dist[current.x][current.y] + 1;
            push(&Q, (LocationPoint){nX, nY});
        }
    }

    return 0;
}