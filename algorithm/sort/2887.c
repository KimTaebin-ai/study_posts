#include <stdio.h>
#include <stdlib.h>

#define MAX 100001

typedef struct
{
    int first;
    int second;
} Pair;

typedef struct
{
    int cost;
    Pair nodes;
} Edge;

Pair X[MAX], Y[MAX], Z[MAX];
Edge edges[MAX * 3];
int parent[MAX];
int edgeCount = 0;

int find(int x)
{
    if (parent[x] == x)
        return x;
    return parent[x] = find(parent[x]);
}

void unite(int a, int b)
{
    a = find(a);
    b = find(b);
    if (a < b)
        parent[b] = a;
    else
        parent[a] = b;
}

int comparePairs(const void *a, const void *b)
{
    return ((Pair *)a)->first - ((Pair *)b)->first;
}

int compareEdges(const void *a, const void *b)
{
    return ((Edge *)a)->cost - ((Edge *)b)->cost;
}

void addEdge(int cost, int a, int b)
{
    edges[edgeCount].cost = cost;
    edges[edgeCount].nodes.first = a;
    edges[edgeCount].nodes.second = b;
    edgeCount++;
}

int main()
{
    int N;
    scanf("%d", &N);

    for (int i = 0; i < N; i++)
    {
        int x, y, z;
        scanf("%d %d %d", &x, &y, &z);
        X[i].first = x;
        X[i].second = i;
        Y[i].first = y;
        Y[i].second = i;
        Z[i].first = z;
        Z[i].second = i;
        parent[i] = i;
    }

    // 각 좌표 축에 대해 정렬
    qsort(X, N, sizeof(Pair), comparePairs);
    qsort(Y, N, sizeof(Pair), comparePairs);
    qsort(Z, N, sizeof(Pair), comparePairs);

    // 간선 추가
    for (int i = 0; i < N - 1; i++)
    {
        addEdge(abs(X[i + 1].first - X[i].first), X[i].second, X[i + 1].second);
        addEdge(abs(Y[i + 1].first - Y[i].first), Y[i].second, Y[i + 1].second);
        addEdge(abs(Z[i + 1].first - Z[i].first), Z[i].second, Z[i + 1].second);
    }

    // 간선 비용을 기준으로 정렬
    qsort(edges, edgeCount, sizeof(Edge), compareEdges);

    int totalCost = 0;
    int edgesUsed = 0;

    // 크루스칼 알고리즘으로 최소 스패닝 트리 구성
    for (int i = 0; i < edgeCount; i++)
    {
        int a = edges[i].nodes.first;
        int b = edges[i].nodes.second;
        int cost = edges[i].cost;

        if (find(a) != find(b))
        {
            unite(a, b);
            totalCost += cost;
            edgesUsed++;
            if (edgesUsed == N - 1)
                break;
        }
    }

    printf("%d\n", totalCost);
    return 0;
}
