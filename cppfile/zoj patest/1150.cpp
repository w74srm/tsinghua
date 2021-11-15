#include <cstdio>
#include <vector>
#include <cstring>
using namespace std;
const int maxn = 205;
int n, m, u, v, dis, k, G[maxn][maxn];
bool vis[maxn];
int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 0; i < m; i++)
    {
        scanf("%d%d%d", &u, &v, &dis);
        G[u][v] = G[v][u] = dis;
    }
    scanf("%d", &k);
    int Min = -1, MinDis;
    for (int i = 1; i <= k; i++)
    {
        int num, cnt = n, t, pre, sum = 0, flag = 0; //num：顶点个数。cnt：统计路径中未访问的顶点数。sum：路径总和。flag0：路径中是否有不存在的边。
        scanf("%d", &num);
        memset(vis, 0, sizeof(vis));
        vector<int> path(num);
        for (int j = 0; j < num; j++)
        {
            scanf("%d", &t);
            path[j] = t;
            if (!vis[t])
            {
                vis[t] = true;
                cnt--;
            }
            if (j != 0)
            {
                if (G[pre][t])
                    sum += G[pre][t];
                else
                    flag = 1;
            }
            pre = t;
        }
        if (flag)
        { //给定路径有不存在的边
            printf("Path %d: NA (Not a TS cycle)\n", i);
            continue;
        }
        if (!cnt && path[0] == path[num - 1] && num > n)
        {
            if (Min == -1)
            {
                Min = i;
                MinDis = sum;
            }
            else if (sum < MinDis)
            {
                Min = i;
                MinDis = sum;
            }
            if (num == n + 1)
                printf("Path %d: %d (TS simple cycle)\n", i, sum);
            else
                printf("Path %d: %d (TS cycle)\n", i, sum);
        }
        else
            printf("Path %d: %d (Not a TS cycle)\n", i, sum);
    }
    printf("Shortest Dist(%d) = %d\n", Min, MinDis);
    return 0;
}