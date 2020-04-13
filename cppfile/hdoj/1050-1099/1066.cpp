#include <iostream>
#include <string>
#include <cstring>
using namespace std;
 
const int MAXN = 10000;
const int mod[20] = { 1, 1, 2, 6, 4, 2, 2, 4, 2, 8, 4, 4, 8, 4, 6, 8, 8, 6, 8, 2 };
 
int lastDigit(char buf[])
{
 
	int len = strlen(buf);
	int a[MAXN];
	if (len == 1)
		return mod[buf[0] - '0'];
	for (int i = 0; i < len; i++)
		a[i] = buf[len - 1 - i] - '0';
 
	int ret = 1;
	while (len)
	{
		ret = ret * mod[a[1] % 2 * 10 + a[0]] % 5;
		for (int c = 0, i = len - 1; i >= 0; i--)
		{
			c = c * 10 + a[i], a[i] = c / 5, c %= 5;
		}
		len -= !a[len - 1];
	}
	return ret + ret % 2 * 5;
}
 
int main()
{
	char n[MAXN];
	while (cin >> n)
	{
		cout << lastDigit(n) << endl;
	}
	return 0;
}
 