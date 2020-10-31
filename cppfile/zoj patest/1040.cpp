#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int getLCstring(string a, string b)
{
    int len = a.length() + 1;
    int dp[len][len];
    for (int i = 0; i < len; i++)
    {
        for (int j = 0; j < len; j++)
        {
            dp[i][j] = 0;
        }
    }
    for (int i = 0; i < len; i++)
    {
        for (int j = 0; j < len; j++)
        {
            if (i == 0 || j == 0)
                dp[i][j] = 0;
            else if (a[i - 1] == b[j - 1])
                dp[i][j] = dp[i - 1][j - 1] + 1;
            else
                dp[i][j] = 0;
        }
    }
    int result = 0;
    for (int i = 1; i < len; i++)
    {
        for (int j = 1; j < len; j++)
        {
            if (dp[i][j] > result)
            {
                result = dp[i][j];
            }
        }
    }
    return result;
}

int main()
{
    string a, b;
    getline(cin, a);
    b = a;
    reverse(b.begin(), b.end());
    int result = getLCstring(a, b);
    cout << result << endl;
    return 0;
}