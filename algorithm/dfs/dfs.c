#include <stdio.h>

#define MAX 502

typedef struct
{
    int x;
    int y;
} LocationPoint;

typedef struct
{
    LocationPoint data[MAX * MAX];
    int top;
} Stack;

int board[MAX][MAX] = {
    {1, 1, 1, 0, 1, 0, 0, 0, 0, 0},
    {1, 0, 0, 0, 1, 0, 0, 0, 0, 0},
    {1, 1, 1, 0, 1, 0, 0, 0, 0, 0},
    {1, 1, 0, 0, 1, 0, 0, 0, 0, 0},
    {0, 1, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}};

int n = 7, m = 10;

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1}; // 상하좌우

int visit[MAX][MAX] = {0}; // 해당 칸 방문 여부를 저장

void initStack(Stack *s) // 스택의 top 값을 0으로 초기화
{
    s->top = 0;
}

void push(Stack *s, LocationPoint p)
{
    s->data[s->top++] = p;
}

int empty(Stack *s)
{
    return s->top == 0;
}

LocationPoint pop(Stack *s)
{
    return s->data[--s->top];
}

int main()
{
    Stack S;
    initStack(&S);

    visit[0][0] = 1;                 // 1. 알고리즘 시작 시 (0, 0) 방문 표시
    push(&S, (LocationPoint){0, 0}); // 2. 해당 칸을 스택에 넣는다.

    while (!empty(&S))
    {
        LocationPoint current = pop(&S); // 3. 초기 세팅 후 스택이 빌 때까지 스택의 top을 빼줌
        printf("(%d, %d) -> ", current.x, current.y);

        // 4. 해당 좌표의 상하좌우를 살펴보며 스택에 넣는다

        for (int dir = 0; dir < 4; dir++) // 상하좌우 살펴보기
        {
            int nX = current.x + dx[dir];
            int nY = current.y + dy[dir]; // nx, ny에 dir에서 정한 방향의 인접한 칸의 좌표가 들어감

            if (nX < 0 || nX >= n || nY < 0 || nY >= m) // 범위 밖일 경우 넘어감
                continue;
            if (visit[nX][nY] || board[nX][nY] != 1) // 이미 방문한 칸이거나 0인 경우
                continue;
            visit[nX][nY] = 1;                 // 조건에 걸리지 않는다면 방문 가능, 방문했음을 저장
            push(&S, (LocationPoint){nX, nY}); // 해당 좌표를 스택에 넣어줌
        }
    }

    return 0;
}