#include <iostream>
#include <cstdio>
#include <cstring>
#define MAX 0x3f3f3f3f
using namespace std;
int n, m, vis[105], low[105], dis[105][105];
int prim()
{
    int i, ans = 0, pos = 1;
    memset(vis, 0, sizeof(vis));
    for (i = 1; i <= n; i++)
        low[i] = dis[i][pos];
    vis[pos] = 1;
    for (;;)
    {
        int min = MAX;
        for (i = 1; i <= n; i++)
            if (!vis[i] && low[i] < min)
            {
                min = low[i];
                pos = i;
            }
        if (min == MAX)
            break;
        vis[pos] = 1;
        ans += min;
        for (i = 1; i <= n; i++)
            if (!vis[i] && dis[pos][i] < low[i])
                low[i] = dis[pos][i];
    }
    return ans;
}
int main()
{
    int i, j;
    while (scanf("%d", &n) != EOF)
    {
        for (i = 1; i <= n; i++)
            for (j = 1; j <= n; j++)
            {
                int t;
                scanf("%d", &t);
                if (i == j)
                    dis[i][j] = MAX;
                else
                    dis[i][j] = dis[j][i] = t;
            }
        scanf("%d", &m);
        for (i = 1; i <= m; i++)
        {
            int a, b;
            scanf("%d%d", &a, &b);
            if (a != b)
                dis[a][b] = dis[b][a] = 0;
        }
        printf("%d\n", prim());
    }
    return 0;
}