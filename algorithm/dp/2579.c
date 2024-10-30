#include <stdio.h>

int s[301];
int n;
int d[301][3];

#define max(x, y) ((x) > (y) ? (x) : (y))

int main()
{
    scanf("%d", &n);

    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &s[i]);
    }

    if (n == 1)
    {
        printf("%d", s[1]);
        return 0;
    }
    else if (n == 2)
    {
        printf("%d", s[1] + s[2]);
        return 0;
    }

    // 초기값 설정
    d[1][1] = s[1];
    d[1][2] = 0;
    d[2][1] = s[2];
    d[2][2] = s[1] + s[2];

    // DP 테이블 채우기
    for (int i = 3; i <= n; i++)
    {
        d[i][1] = max(d[i - 2][1], d[i - 2][2]) + s[i];
        d[i][2] = d[i - 1][1] + s[i];
    }

    // 최종 결과 출력
    printf("%d", max(d[n][1], d[n][2]));

    return 0;
}
