#include <iostream>
#include <string>
#include<cstring>
using namespace std;
 
const int N = 1000;
struct Bint //底数
{
	int num[N]; //去掉小数点和多余的0之后，剩余的数
	int p; //整数位数
	int del; //小数位数
	int len; // 总数位长度
};
 
int Find(char a, char str[]) //返回整数部分的位数
{
	int i, len = strlen(str);
	for (i = 0; i < len; i++)
	{
		if (str[i] == a)
			return i;
	}
	return len;
}
 
void print(Bint s) //输出
{
	int i;
	for (i = s.p + s.del - 1; i >= s.del; i--)
		cout << s.num[i];
	if (s.del > 0)
	{
		cout << ".";
		for (i = s.del - 1; i >= 0; i--)
			cout << s.num[i];
	}
	cout << endl;
}
 
void trans(Bint &a, char str[]) //将输入的字符串形式的数转换为结构体
{
	memset(a.num, 0, sizeof(a.num));
	int len = strlen(str);
	a.p = Find('.', str);
	a.del = (len == a.p) ? 0 : (len - a.p - 1);
	int i = 0, k = 0, pa = a.p, l = len - 1;
	while (str[i++] == '0'&&i <= pa)
		a.p--;
	while (str[l--] == '0'&&l >= pa)
		a.del--;
	for (i = pa + a.del; i > pa; i--)
		a.num[k++] = str[i] - '0';
	for (i = pa - 1; i >= pa - a.p; i--)
		a.num[k++] = str[i] - '0';
	a.len = k;
}
 
Bint mul(Bint a, Bint b) //大数乘法，值存到结构体中
{
	Bint m;
	memset(m.num, 0, sizeof(m.num));
	int i, j;
	for (i = 0; i < a.len; i++)
	{
		for (j = 0; j < b.len; j++)
		{
			m.num[i + j] += a.num[i] * b.num[j];
		}
	}
	m.del = a.del + b.del;
	m.len = a.len + b.len - 1;
	for (i = 0; i < m.len; i++)
	{
		if (m.num[i] >= 10)
		{
			m.num[i + 1] += m.num[i] / 10;
			m.num[i] %= 10;
		}
	}
	if (m.num[m.len] > 0 && m.num[m.len] < 10)
		m.len += 1;
	else if (m.num[m.len] > 10)
	{
		m.num[m.len + 1] += m.num[m.len] / 10;
		m.num[m.len] %= 10;
		m.len += 2;
	}
	m.p = m.len - m.del;
	return m;
}
 
int main()
{
	char str[N];
	Bint a, s;
	int n, i;
	while (cin >> str >> n)
	{
		trans(a, str);
		trans(s, str);
		for (i = 1; i < n; i++)
			s = mul(s, a);
		print(s);
	}
	return 0;
}