#include <stdio.h>

int N, M;
int num[10];
int arr[10];
int isUsed[10];

void func(int k)
{
    if (!k)
    {
        for (int i = 0; i < M; i++)
        {
            printf("%d ", arr[i]);
        }

        printf("\n");
        return;
    }

    for (int i = 0; i < N; i++)
    {
        if (!isUsed[i])
        {
            isUsed[i] = 1;
            arr[M - k] = num[i];

            func(k - 1);
            isUsed[i] = 0;
        }
    }
}

int main()
{
    scanf("%d %d", &N, &M);

    for (int i = 0; i < N; i++)
    {
        scanf("%d", &num[i]);
    }

    int temp;

    for (int i = 0; i < N; i++)
    {
        for (int j = i + 1; j < N; j++)
        {
            if (num[i] > num[j])
            {
                temp = num[i];
                num[i] = num[j];
                num[j] = temp;
            }
        }
    }

    func(M);

    return 0;
}
