#include <stdio.h>
#include <stdbool.h>

#define MAX 502

// Point 구조체 정의 (pair 대체)
typedef struct
{
    int x;
    int y;
} Point;

// Queue 구조체 정의
typedef struct
{
    Point data[MAX * MAX];
    int front;
    int rear;
} Queue;

// 전역 변수 선언
int board[MAX][MAX] = {
    {1, 1, 1, 0, 1, 0, 0, 0, 0, 0},
    {1, 0, 0, 0, 1, 0, 0, 0, 0, 0},
    {1, 1, 1, 0, 1, 0, 0, 0, 0, 0},
    {1, 1, 0, 0, 1, 0, 0, 0, 0, 0},
    {0, 1, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}};
bool vis[MAX][MAX] = {false};
int n = 7, m = 10;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

// Queue 함수 구현
void initQueue(Queue *q)
{
    q->front = 0;
    q->rear = 0;
}

void push(Queue *q, Point p)
{
    q->data[q->rear++] = p;
}

Point pop(Queue *q)
{
    return q->data[q->front++];
}

bool empty(Queue *q)
{
    return q->front == q->rear;
}

int main(void)
{
    Queue Q;
    initQueue(&Q);

    vis[0][0] = true;
    push(&Q, (Point){0, 0});

    while (!empty(&Q))
    {
        Point cur = pop(&Q);
        printf("(%d, %d) -> ", cur.x, cur.y);

        for (int dir = 0; dir < 4; dir++)
        {
            int nx = cur.x + dx[dir];
            int ny = cur.y + dy[dir];

            if (nx < 0 || nx >= n || ny < 0 || ny >= m)
                continue;
            if (vis[nx][ny] || board[nx][ny] != 1)
                continue;

            vis[nx][ny] = true;
            push(&Q, (Point){nx, ny});
        }
    }

    return 0;
}