#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
const int maxn = 510;
int N, M;
vector<int> Adj[maxn];
bool vis[maxn] = {false};
int degree[maxn] = {0};
int odds = 0, evens = 0;
void DFS(int s)
{
    vis[s] = true;
    for (int i = 0; i < Adj[s].size(); i++)
    {
        int v = Adj[s][i];
        if (!vis[v])
        {
            DFS(v);
        }
    }
}
int DFStraverse()
{
    int count = 0;
    for (int i = 1; i <= N; i++)
    {
        if (!vis[i])
        {
            count++;
            DFS(i);
        }
    }
    return count;
}
int main()
{
    scanf("%d%d", &N, &M);
    int u, v;
    for (int i = 0; i < M; i++)
    {
        scanf("%d%d", &u, &v);
        Adj[u].push_back(v);
        Adj[v].push_back(u);
        degree[u]++;
        degree[v]++;
    }
    for (int i = 1; i <= N; i++)
    {
        if (i > 1)
            printf(" ");
        printf("%d", degree[i]);
        if (degree[i] % 2 == 0)
            evens++;
        else
            odds++;
    }
    printf("\n");
    if (DFStraverse() == 1)
    {
        if (odds == 0)
            printf("Eulerian");
        else if (odds == 2)
            printf("Semi-Eulerian");
        else
            printf("Non-Eulerian");
    }
    else
        printf("Non-Eulerian");
    return 0;
}