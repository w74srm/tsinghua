#include <bits\stdc++.h>
using namespace std;
int a[105][105];
#define INF 1e9
int main()
{
    int n;
    while (scanf("%d", &n) != EOF)
    {
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
            {
                scanf("%d", &a[i][j]);
                a[i][j] += a[i][j - 1];
            }
        int ans = -INF;
        int res;
        for (int i = 1; i <= n; i++)
            for (int j = i; j <= n; j++)
                for (int k = 1, res = 0; k <= n; k++)
                {
                    res += a[k][j] - a[k][i - 1];
                    if (res < 0)
                        res = 0;
                    ans = max(ans, res);
                }
        printf("%d\n", ans);
    }
}
