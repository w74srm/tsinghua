#include<bits/stdc++.h>
using namespace std;


int get_min_cost(string str1, string str2) {
    // write code here
    int len1 = str1.size();
    int len2 = str2.size();
    vector< vector <int> > dp(len2 + 1, vector<int> (len1 + 1));
    for(int i = 0 ; i < len2 + 1; i++)
    {
        dp[i][0] = i;
    }
    for(int i = 0 ; i < len1 + 1; i++)
    {
        dp[0][i] = 2 * i;
    }
    for(int i = 1; i < len2 + 1; i++)
    {
        for(int j = 1; j < len1 + 1; j++)
        {
            if(str1[j-1] == str2[i - 1]) dp[i][j] = min(dp[i-1][j-1], min(dp[i-1][j], dp[i][j-1]));
            else
            {
                dp[i][j] = min(dp[i-1][j-1] + 3, min(dp[i-1][j] + 1, dp[i][j-1] + 2));
            }
        }
    }
    return dp[len2][len1];
}


int main(){
    string str1, str2;
    cin >> str1;
    cin >> str2;
    double max = 0;
    int res = get_min_cost(str1, str2);
    cout << res;
    return 0;
}