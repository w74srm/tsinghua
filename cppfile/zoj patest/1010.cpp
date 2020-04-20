#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

long long toNum(char c)
{
	int num;
	if (c >= '0' && c <= '9')
		num = c - '0';
	else num = c - 'a' + 10;
	return num;
}
long long trans(string n_str, long long radix)//将radix进制数转化为十进制数
{
	long long tmp = 1, sum = 0;
	for (int i = n_str.size() - 1; i >= 0; --i)
	{
		sum += tmp * toNum(n_str[i]);
		tmp *= radix;
		if (sum < 0 || tmp < 0)//如果溢出，返回-1
			return -1;
	}
	return sum;
}

int main()
{
	string N1, N2;
	int tag, radix;
	cin >> N1 >> N2 >> tag >> radix;
	long long l, r, mid, base;
	if (tag == 2)
		swap(N1, N2);
	l = 2;
	base = r = trans(N1, radix);//右边界为基准数
	for (auto& item : N2)
	{
		l = max(l, toNum(item) + 1);//左边界为最低进制数
	}
	while (r >= l)//采用二分法，否则超时
	{
		mid = (l + r) >> 1;
		long long t = trans(N2, mid);
		if (t >= base || t < 0)//此处有=的原因是题目要求输出最小进制
			r = mid - 1;
		else l = mid + 1;

	}
	if (trans(N2, l) == base)//l保证符合要求的结果最小
		cout << l;
	else
		printf("Impossible");
	return 0;
}
