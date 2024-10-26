#include <stdio.h>

int N, M;
int arr[10];
int isUsed[10];

void func(int k)
{
    if (k == M)
    {
        for (int i = 0; i < M; i++)
        {
            printf("%d ", arr[i]);
        }
        printf("\n");
        return;
    }

    for (int i = 1; i <= N; i++)
    {
        if (!isUsed[i])
        {
            arr[k] = i;
            isUsed[i] = 1;
            func(k + 1);
            isUsed[i] = 0;
        }
    }
}

int main()
{
    scanf("%d %d", &N, &M);
    func(0);
}