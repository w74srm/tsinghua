#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int n[1010];
int dp[1010], N;

int main()
{
    while ((scanf("%d", &N) != EOF) and N)
    {
        for (int i = 0; i < N; ++i)
            scanf("%d", n + i);

        memset(dp, 0, sizeof(dp));

        int maxt;
        for (int i = 0; i < N; ++i)
        {
            maxt = 0;
            for (int j = 0; j <= i; ++j)
            {
                if (n[j] < n[i])
                { //找到可以走到当前格子的最大点数和
                    maxt = max(maxt, dp[j]);
                }
            }
            dp[i] = maxt + n[i]; //加上当前格子点数即为走到当前格子时的最大点数和
        }

        int ans = -0x3f3f3f3f;
        for (int i = 0; i < N; ++i)
        {
            ans = max(ans, dp[i]);
        }
        printf("%d\n", ans);
    }
    return 0;
}
