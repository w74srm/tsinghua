#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
const int maxn = 100 + 10;
int a[maxn][maxn], d[maxn][maxn], vis[maxn][maxn];
int k, n;
int dp(int i, int j)
{
    if (vis[i][j])
        return d[i][j];
    if (i < 0 || j >= n || j < 0 || i >= n)
        return 0;
    vis[i][j] = 1;
    for (int m = 1; m <= k; m++)
    {
        if ((i - m) >= 0 && a[i - m][j] > a[i][j])
            d[i][j] = max(d[i][j], dp(i - m, j)); //四个方向
        if ((i + m) < n && a[i + m][j] > a[i][j])
            d[i][j] = max(d[i][j], dp(i + m, j));
        if ((j + m) < n && a[i][j + m] > a[i][j])
            d[i][j] = max(d[i][j], dp(i, j + m));
        if ((j - m) >= 0 && a[i][j - m] > a[i][j])
            d[i][j] = max(d[i][j], dp(i, j - m));
    }

    d[i][j] += a[i][j];
    return d[i][j];
}
int main()
{
    int i, j, Max;
    while (~scanf("%d %d", &n, &k) && (n != -1 || k != -1))
    {
        memset(vis, 0, sizeof(vis));
        memset(d, 0, sizeof(d));
        Max = -1;
        for (i = 0; i < n; i++)
            for (j = 0; j < n; j++)
                scanf("%d", &a[i][j]);
        printf("%d\n", dp(0, 0));
    }
    return 0;
}