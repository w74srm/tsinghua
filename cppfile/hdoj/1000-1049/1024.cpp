#include <iostream>
#include <cstring>
using namespace std;
const int N = 1000010;
 
int m, n;
int num[N];
int dp[N];
int pre[N];
 
int max(int a, int b)
{
	return a > b ? a : b;
}
 
int main()
{
	while (cin >> m >> n)
	{
		for (int i = 1; i <= n; i++) 
			cin >> num[i];
		num[0] = 0;
		memset(dp, 0, sizeof(dp)); 
		memset(pre, 0, sizeof(pre));
		int Sum;
		for (int i = 1; i <= m; i++)
		{
			Sum = -9999999;
			for (int j = i; j <= n; j++)
			{
				dp[j] = max(dp[j - 1], pre[j - 1]) + num[j];
				pre[j - 1] = Sum;
				Sum = max(Sum, dp[j]);
			}
		}
		cout << Sum << endl;
	}
	return 0;
}