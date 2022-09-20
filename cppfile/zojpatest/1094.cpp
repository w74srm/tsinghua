#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

const int maxn = 100;
vector<int> children[maxn];
int level[maxn] = {0};
int N, M;

void BFS(int root)
{
    queue<int> Q;
    Q.push(root);
    level[root] = 1;
    while (!Q.empty())
    {
        int t = Q.front();
        Q.pop();
        if (children[t].size())
        {
            for (int i = 0; i < children[t].size(); i++)
            {
                Q.push(children[t][i]);
                level[children[t][i]] = level[t] + 1;
            }
        }
    }
}

int hashtable[maxn] = {0};

int main()
{
    scanf("%d%d", &N, &M);
    int father, k, child;
    for (int i = 0; i < M; i++)
    {
        scanf("%d %d", &father, &k);
        for (int j = 0; j < k; j++)
        {
            scanf("%d", &child);
            children[father].push_back(child);
        }
    }
    BFS(1);
    for (int i = 1; i <= N; i++)
    {
        hashtable[level[i]]++;
    }
    int maxL = -1, maxl;
    for (int i = 1; i <= N; i++)
    {
        if (maxL < hashtable[i])
        {
            maxL = hashtable[i];
            maxl = i;
        }
    }
    printf("%d %d", maxL, maxl);
    return 0;
}