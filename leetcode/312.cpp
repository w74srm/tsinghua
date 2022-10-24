#include<bits/stdc++.h>
using namespace std;


int main()
{
    int n;
    cin >> n;
    vector<int> val(n+2);
    val[0] = val[n + 1] = 1;
    for(int i = 1; i <= n; i++)
    {
        cin >> val[i];
    }
    vector<vector<int>> dp(n+2, vector<int>(n+2));
    for(int i = n-1; i>= 0; i--)
    {
        for(int j = i + 2; j <= n + 1; j++)
        {
            for(int k = i + 1; k < j; k++)
            {
                int sum = val[i] * val[k] * val[j];
                sum += dp[i][k] + dp[k][j];
                dp[i][j] = max(sum, dp[i][j]);
            }
        }
    }
    cout << dp[0][n+1] << endl;
    return 0;
}