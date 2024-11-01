#include <stdio.h>

int n, m, pos = -1, last = 0, cur = 0, map[100001] = {};

int q[200002];

int main()
{
    scanf("%d %d", &n, &m);

    if (n == m)
    {
        printf("0\n");
        return (0);
    }

    q[last++] = n;

    while (cur < last && map[m] == 0)
    {
        pos = q[cur++];

        if (0 <= pos - 1 && map[pos - 1] == 0)
        {
            q[last++] = pos - 1;
            map[pos - 1] = map[pos] + 1;
        }

        if (pos + 1 <= 100000 && map[pos + 1] == 0)
        {
            q[last++] = pos + 1;
            map[pos + 1] = map[pos] + 1;
        }

        if (pos * 2 <= 100000 && map[pos * 2] == 0)
        {
            q[last++] = pos * 2;
            map[pos * 2] = map[pos] + 1;
        }
    }
    printf("%d\n", map[m]);
    return (0);
}
