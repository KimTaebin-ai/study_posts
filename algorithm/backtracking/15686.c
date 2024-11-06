#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAX 50

typedef struct
{
    int x, y;
} Position;

Position houses[MAX * 2];
Position chickens[MAX * 2];

int N, M, house_count = 0, chicken_count = 0;
int selected[MAX * 2];
int min_distance = INT_MAX;

int abs(int x)
{
    return x < 0 ? -x : x;
}

int calc_chicken_distance()
{
    int total_distance = 0;

    for (int i = 0; i < house_count; i++)
    {
        int hx = houses[i].x;
        int hy = houses[i].y;
        int min_dist = INT_MAX;

        for (int j = 0; j < chicken_count; j++)
        {
            if (selected[j])
            {
                int cx = chickens[j].x;
                int cy = chickens[j].y;
                int dist = abs(hx - cx) + abs(hy - cy);
                if (dist < min_dist)
                {
                    min_dist = dist;
                }
            }
        }
        total_distance += min_dist;
    }

    return total_distance;
}

void backtrack(int idx, int count)
{
    if (count == M)
    {
        int distance = calc_chicken_distance();
        if (distance < min_distance)
        {
            min_distance = distance;
        }
        return;
    }

    for (int i = idx; i < chicken_count; i++)
    {
        if (!selected[i])
        {
            selected[i] = 1;
            backtrack(i + 1, count + 1);
            selected[i] = 0;
        }
    }
}

int main()
{
    scanf("%d %d", &N, &M);

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            int val;
            scanf("%d", &val);
            if (val == 1)
            {
                houses[house_count++] = (Position){i, j};
            }
            else if (val == 2)
            {
                chickens[chicken_count++] = (Position){i, j};
            }
        }
    }

    backtrack(0, 0);

    printf("%d\n", min_distance);
    return 0;
}
