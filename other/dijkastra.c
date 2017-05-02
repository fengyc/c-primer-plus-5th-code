//
// Created by fengyingcai on 2017/4/28.
//

/**
 * dijkstra 算法，单源到其它各顶点的最短路径
 */

#include <stdio.h>

#define INF 32767   // 表示无穷
#define N 6         // 顶点数


void dijkstra(int g[N][N], int n, int v0, int dist[N], int prev[N])
{
    int s[N] = {0};    // s 集合，为源顶点集合
    int i;

    // 初始化 dist
    for (i=0; i<n; i++)
    {
        dist[i] = g[v0][i];
        s[i] = 0;          // 表示未有加入到 s 集合
        /* 前驱节点初始化 */
        if (dist[i] == INF) {
            prev[i] = -1;
        }
        else {
            prev[i] = v0;
        }
    }
    dist[v0] = 0;
    s[v0] = 1;

    /* 开始计算，对其余 n-1 个节点 */
    for (i=1; i < n; i++)
    {
        int mindist = INF;  // 初始化 s 中节点到剩余节点距离为 INF
        int u;              // 保存与最小距离的剩余节点
        int j;
        for (j=0; j<n; j++)
        {
            /* 找到距离更加近的点 */
            if(s[j]==0 && dist[j] < mindist) {
                u = j;
                mindist = dist[j];
            }
        }
        s[u] = 1;
        /* 更新距离 */
        for (j=0; j<n; j++)
        {
            if(s[j]==0 && g[u][j] < INF && (dist[u] + g[u][j] < dist[j]))
            {
                dist[j] = dist[u] + g[u][j];
                prev[j] = u;    // 记录前驱顶点
            }
        }
    }
}

void printPath(int prev[N], int v0, int v)
{
    if (v==v0){
        printf("%d", v0);
        return;
    }
    printPath(prev, v0, prev[v]);
    printf("->%d", v);
}

int main(void)
{
    int g[N][N] = {
            {0, 7, 9, INF, INF, 16},
            {7, 0, 10, 15, INF, INF},
            {9, 10, 0, 11, INF, 2},
            {INF, 15, 11, 0, 6, INF},
            {INF, INF, INF, 6, 0, 9},
            {14, INF, 2, INF, 9, 0}
    };
    int v0 = 0;
    int dist[N];
    int prev[N];    // 记录前驱节点，用于重建最短路径
    int i, j;

    dijkstra(g, N, v0, dist, prev);

    for (i=0; i < N; i++)
    {
        // 路径
        printPath(prev, v0, i);
        printf(" :%d\n", dist[i]);
    }

    return 0;
}
