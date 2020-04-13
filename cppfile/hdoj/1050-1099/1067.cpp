#include <iostream>
#include <algorithm>
#include <string>
#include <queue>
#include<cstring>
using namespace std;
 
int aim[32] =
{
	11, 12, 13, 14, 15, 16, 17, 0,
	21, 22, 23, 24, 25, 26, 27, 0,
	31, 32, 33, 34, 35, 36, 37, 0,
	41, 42, 43, 44, 45, 46, 47, 0
}; //目标状态
char mp[4][8]; //输入
bool book[1000008]; //访问状态
 
struct point
{
	int r; //行数
	int c; //列数
};
struct node //一个数组状态
{
	point num[48]; //全部格子
	point zero[4]; //空格子
	string mp; //整个数组转换为的字符串
	int step; //步数
}st;
 
int Hash(string s) //求字符串的哈希值
{
	long long sum = 0;
	for (int i = 0; i < 32; i++)
		sum = sum * 2 + s[i]; //将字符串转换为一个较大且不重复的整数（方法不唯一）
	return sum % 1000007; //哈希值（方法不唯一）
}
 
int bfs()
{
	queue<node> q;
	while (!q.empty()) //清空队列
		q.pop();
	st.step = 0; 
	q.push(st);
	string s = ""; //目标状态字符串
	for (int i = 0; i < 32; i++)
		s.push_back(aim[i]);
	int END = Hash(s); //目标哈希值
 
	while (!q.empty())
	{
		node temp, next;
		temp = q.front();
		q.pop();
		if (Hash(temp.mp) == END) //达到目标状态
			return temp.step;
	
		for (int i = 0; i < 4; i++) //四个空格子
		{
			next = temp;
			next.step++;
			point &a = next.zero[i];
			int m = a.r * 8 + a.c - 1; //此空格子在字符串中的左边一位
			int n = next.mp[m];
			if (n % 10 == 7 || n == 0) //空格子左边为尾数为7的数或空格子
				continue;
			n++; //应该填入该空格子中的数
			point &b = next.num[n];
			int o = b.r * 8 + b.c; //交换的数的位置
			m++; //空格子位置
			swap(next.mp[m], next.mp[o]); //空格子和对应的数交换（在字符串中）
			int x = Hash(next.mp);
			if (book[x])
				continue;
			book[x] = 1;
			swap(a, b); //空格子的坐标和对应数的坐标交换
			q.push(next);
		}
	}
	return -1;
}
 
void solve()
{
	int cnt = 0; //空格子数组索引
	st.mp.clear();
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			if (mp[i][j] == 0) //空格子
			{
				st.zero[cnt].r = i;
				st.zero[cnt++].c = j;
			}
			else //非空格子
			{
				st.num[mp[i][j]].r = i;
				st.num[mp[i][j]].c = j;
			}
			st.mp.push_back(mp[i][j]); //加入字符串（将整个数组状态转换为一个字符串）
		}
	}
	memset(book, 0, sizeof(book));
	book[Hash(st.mp)] = 1;
	cout << bfs() << endl;
}
 
int main()
{
	int t, x;
	cin >> t;
	while (t--)
	{
		memset(mp, 0, sizeof(mp));
		for (int i = 0; i < 4; i++)
		{
			for (int j = 1; j < 8; j++)
			{
				cin >> x;
				mp[i][j] = (char)x;
				if (x % 10 == 1) //将11,21,31,41换到对应的位置上
					swap(mp[i][j], mp[x/10 - 1][0]);
			}
		}
		solve();
	}
	return 0;
}