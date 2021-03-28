#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
const int maxn = 510;
const int INF = 1000000000;
int N, M, e, s;
bool vis[maxn] = {false};
int G[maxn][maxn], Gt[maxn][maxn];
int d[maxn]; //边权
int w[maxn]; //点权
int t[maxn]; //边权
int preMIND[maxn], preMINT[maxn];
void DijkstraD(int s)
{
    fill(d, d + maxn, INF);
    fill(t, t + maxn, INF);
    fill(vis, vis + maxn, false);
    fill(preMIND, preMIND + maxn, -1);
    d[s] = 0;
    t[s] = 0;
    for (int i = 0; i < N; i++)
    {
        int MIN = INF, id = -1;
        for (int j = 0; j < N; j++)
        {
            if (!vis[j] && MIN > d[j])
            {
                MIN = d[j];
                id = j;
            }
        } //找最小
        if (id == -1)
            return;
        vis[id] = true;
        for (int j = 0; j < N; j++)
        {
            if (!vis[j] && G[id][j] != INF)
            {
                if (d[id] + G[id][j] < d[j])
                {
                    d[j] = d[id] + G[id][j];
                    t[j] = t[id] + Gt[id][j]; //注意这个也要顺便更新
                    preMIND[j] = id;
                }
                else if (d[j] == d[id] + G[id][j])
                {
                    if (t[j] > t[id] + Gt[id][j])
                    {
                        t[j] = t[id] + Gt[id][j];
                        preMIND[j] = id;
                    }
                }
            }
        }
    }
}
void DijkstraT(int s)
{
    fill(t, t + maxn, INF);
    fill(w, w + maxn, 1);
    fill(vis, vis + maxn, false);
    fill(preMINT, preMINT + maxn, -1);
    w[s] = 1;
    t[s] = 0;
    for (int i = 0; i < N; i++)
    {
        int MIN = INF, id = -1;
        for (int j = 0; j < N; j++)
        {
            if (!vis[j] && MIN > t[j])
            {
                MIN = t[j];
                id = j;
            }
        } //找最小
        if (id == -1)
            return;
        vis[id] = true;
        for (int j = 0; j < N; j++)
        {
            if (!vis[j] && Gt[id][j] != INF)
            {
                if (t[id] + Gt[id][j] < t[j])
                {
                    t[j] = t[id] + Gt[id][j];
                    w[j] = w[id] + 1; //这样的尤其要注意，不是只在比较第二标尺时才更新
                    preMINT[j] = id;
                }
                else if (t[j] == t[id] + Gt[id][j])
                {
                    if (w[j] > w[id] + 1)
                    {
                        w[j] = w[id] + 1;
                        preMINT[j] = id;
                    }
                }
            }
        }
    }
}
void printPath(int *pre, int e1)
{
    if (e1 == -1)
        return;
    printPath(pre, pre[e1]);
    printf("%d", e1);
    if (e1 != e)
        printf(" -> ");
}
int main()
{
    scanf("%d %d", &N, &M);
    fill(G[0], G[0] + maxn * maxn, INF);   //记住一定要初始化
    fill(Gt[0], Gt[0] + maxn * maxn, INF); //记住一定要初始化
    int V1, V2, oneway, length, time;
    for (int i = 0; i < M; i++)
    {
        scanf("%d%d%d%d%d", &V1, &V2, &oneway, &length, &time);
        G[V1][V2] = length;
        Gt[V1][V2] = time;
        if (oneway == 0)
        {
            G[V2][V1] = length;
            Gt[V2][V1] = time;
        }
    }
    scanf("%d %d", &s, &e);
    DijkstraD(s);
    DijkstraT(s);
    bool flag = false;
    int e2 = e;
    while (preMIND[e2] != -1 && preMINT[e2] != -1)
    {
        if (preMIND[e2] == preMINT[e2])
        {
            e2 = preMIND[e2];
        }
        else
            break;
    }
    if (!(preMIND[e2] == -1 && preMINT[e2] == -1))
        flag = true;
    printf("Distance = %d", d[e]);
    if (flag)
    {
        printf(": ");
        printPath(preMIND, e);
        printf("\n");
    }
    else
        printf("; ");
    printf("Time = %d: ", t[e]);
    printPath(preMINT, e);
    return 0;
}