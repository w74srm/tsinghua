#include <cstdio>
#include <set>
#include <algorithm>
using namespace std;
const int maxn = 210;
const int INF = 1000000000;
int a[maxn];
int G[maxn][maxn];
int main()
{
    fill(G[0], G[0] + maxn * maxn, INF);
    int N, M;
    scanf("%d %d", &N, &M);
    int v1, v2;
    for (int i = 0; i < M; i++)
    {
        scanf("%d %d", &v1, &v2);
        G[v1][v2] = 1;
        G[v2][v1] = 1;
    }
    int K;
    scanf("%d", &K);
    int n;
    set<int> s;
    bool flag = false;
    for (int i = 0; i < K; i++)
    {
        scanf("%d", &n);

        for (int j = 0; j < n; j++)
        {
            scanf("%d", &a[j]);
            s.insert(a[j]);
        }
        if (n != N + 1 || s.size() != N)
        {
            printf("NO\n");
        }
        else
        {
            int j = 0;
            if (n == N + 1 && s.size() == N)
            {
                for (j = 0; j < n - 1; j++)
                {
                    if (G[a[j]][a[j + 1]] == 1 && a[0] == a[n - 1])
                        continue;
                    else
                    {
                        printf("NO\n");
                        break;
                    }
                }
                if (j == n - 1)
                {
                    printf("YES\n");
                }
            }
        }
        s.clear();
    }
    return 0;
}