#include <iostream>
#include <stdio.h>
#include <memory.h>
#include <vector>
using namespace std;

const int maxp = 105;
const int maxn = 305;

int P, N;
int link[maxn];
int vis[maxn];
vector<int> g[maxp];

int dfs(int u)
{
    for (int i = 0; i < g[u].size(); i++)
    {
        int v = g[u][i];
        if (!vis[v])
        {
            vis[v] = true;
            if (link[v] == -1 || dfs(link[v]))
            {
                link[v] = u;
                return 1;
            }
        }
    }
    return 0;
}

int hungry()
{
    int res = 0;
    memset(link, -1, sizeof(link));
    for (int i = 1; i <= P; i++)
    {
        memset(vis, 0, sizeof(vis));
        res += dfs(i);
    }
    return res;
}

int main()
{
    //freopen("in.txt","r",stdin);
    int T, num, stu;
    scanf("%d", &T);
    while (T--)
    {
        scanf("%d%d", &P, &N);
        for (int i = 1; i <= P; i++)
            g[i].clear();
        for (int i = 1; i <= P; i++)
        {
            scanf("%d", &num);
            while (num--)
            {
                scanf("%d", &stu);
                g[i].push_back(stu);
            }
        }
        if (hungry() == P)
            printf("YES\n");
        else
            printf("NO\n");
    }
    return 0;
}