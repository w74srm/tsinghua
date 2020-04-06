#include <iostream>
#include<cstring>
using namespace std;
 
int dp[130][130]; 
int split(int n, int m); 
 
int main()
{
	int N;
	
	while (cin >> N)
	{
		memset(dp, 0, sizeof(dp));
		cout << split(N, N) << endl;
	}
	return 0;
}
 
int split(int n, int m)
{
	if (dp[n][m] > 0)
		return dp[n][m];
	else if (n == 0 || m == 0)
		return dp[n][m] = 0;
	else if (n == 1 || m == 1)
		return dp[n][m] = 1;
	else if (m > n)
		return dp[n][m] = split(n, n);
	else if (m == n)
		return dp[n][m] = split(n, m - 1) + 1;
	else
		return dp[n][m] = split(n, m - 1) + split(n - m, m);
}