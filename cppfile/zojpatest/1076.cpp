#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

const int maxn = 1010;
bool inq[maxn] = {false};
vector<int> G[maxn];
int N, L, M, uid, K, query;

int BFS(int start)
{
    fill(inq, inq + maxn, false);
    int potential = 0;
    queue<int> Q;
    Q.push(start);
    inq[start] = true;
    int level = 0;
    int lastnode = start, newLastNode;
    while (!Q.empty())
    {
        int f = Q.front();
        Q.pop();
        if (G[f].size())
        {
            for (int i = 0; i < G[f].size(); i++)
            {
                int t = G[f][i];
                if (!inq[t])
                {
                    Q.push(t);
                    inq[t] = true;
                    newLastNode = t;
                }
            }
        }
        if (level >= 1 && level <= L)
        {
            potential++;
        }
        if (f == lastnode)
        {
            lastnode = newLastNode;
            level++;
        }
    }
    return potential;
}

int main()
{
    scanf("%d %d", &N, &L);
    for (int i = 1; i <= N; i++)
    {
        scanf("%d", &M);
        for (int j = 0; j < M; j++)
        {
            scanf("%d", &uid);
            G[uid].push_back(i);
        }
    }
    scanf("%d", &K);
    for (int i = 0; i < K; i++)
    {
        scanf("%d", &query);
        printf("%d\n", BFS(query));
    }
    return 0;
}