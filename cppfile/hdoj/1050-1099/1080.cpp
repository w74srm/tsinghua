#include <iostream>
#include <stdio.h>
using namespace std;
const int maxn = 105;

int table[5][5] = {
    {5, -1, -2, -1, -3},
    {-1, 5, -3, -2, -4},
    {-2, -3, 5, -2, -2},
    {-1, -2, -2, 5, -1},
    {-3, -4, -2, -1, 0}};

int transfer(char c)
{
    if (c == 'A')
        return 0;
    if (c == 'C')
        return 1;
    if (c == 'G')
        return 2;
    if (c == 'T')
        return 3;
    return 4;
}

int main()
{
    //freopen("in.txt","r",stdin);
    char s1[maxn], s2[maxn];
    int t1[maxn], t2[maxn];
    int dp[maxn][maxn];
    int l1, l2;
    int T;
    scanf("%d", &T);
    while (T--)
    {
        //dp[0][0]=dp[1][0]=dp[0][1]=0;
        scanf("%d ", &l1);
        for (int i = 1; i <= l1; i++)
        {
            scanf("%c", &s1[i]);
            t1[i] = transfer(s1[i]);
        }
        scanf("%d ", &l2);
        for (int i = 1; i <= l2; i++)
        {
            scanf("%c", &s2[i]);
            t2[i] = transfer(s2[i]);
        }
        dp[0][0] = 0;
        for (int i = 1; i <= l1; i++)
            dp[i][0] = dp[i - 1][0] + table[t1[i]][4]; //注意开头是可以填空格的
        for (int i = 1; i <= l2; i++)
            dp[0][i] = dp[0][i - 1] + table[4][t2[i]];
        for (int i = 1; i <= l1; i++)
        {
            for (int j = 1; j <= l2; j++)
            {
                dp[i][j] = max(dp[i - 1][j - 1] + table[t1[i]][t2[j]], max(dp[i - 1][j] + table[t1[i]][4], dp[i][j - 1] + table[4][t2[j]]));
            }
        }
        printf("%d\n", dp[l1][l2]);
    }
    return 0;
}