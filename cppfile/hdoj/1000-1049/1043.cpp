#include <iostream>
#include <cstring>
#include <queue>
#include <cmath>
#include <cctype>
using namespace std;
 
struct S 
{
	char maze[3][3];
	int x, y; 
	int g, h, f; 
	S(){}
	S(const S & ts)
	{
		memcpy(maze, ts.maze, sizeof(maze));
		x = ts.x; y = ts.y;
		g = ts.g; h = ts.h; f = ts.f;
	}
	friend bool operator <(const S& a, const S& b)
	{
		if (a.f == b.f)
			return a.g < a.g;
		return a.f > b.f;
	}
}s;
 
const int fac[] = { 1, 1, 2, 6, 24, 120, 720, 5040, 40320 };
bool vis[363000]; 
int pre[363000]; 
char op[363000]; 
 
int inv_hash(S ts)
{
	char str[10];
	int ans = 0; 
	for (int i = 0; i < 3; i++)
	for (int j = 0; j < 3; j++)
	{
		str[i * 3 + j] = ts.maze[i][j];
		int cnt = 0;
		for (int k = i * 3 + j - 1; k >= 0; k--)
		if (str[k] > str[i * 3 + j]) cnt++;
		ans += fac[i * 3 + j] * cnt;
	}
	return ans;
}
 
const int pos[][2] = { { 0, 0 }, { 0, 1 }, { 0, 2 }, { 1, 0 }, { 1, 1 }, { 1, 2 }, { 2, 0 }, { 2, 1 }, { 2, 2 } };
int h(S ts)
{
	int val = 0;
	for (int i = 0; i < 3; i++)
	for (int j = 0; j < 3; j++)
	{
		if (ts.maze[i][j] == 'x')
			continue;
		int c = ts.maze[i][j] - '1';
		val += abs(pos[c][0] - i) + abs(pos[c][1] - j);
	}
	return val;
}
 
const int dir[4][2] = { { 1, 0 }, { 0, 1 }, { -1, 0 }, { 0, -1 } }; 
bool bfs() 
{
	memset(vis, 0, sizeof(vis));
	priority_queue<S> qu;
	qu.push(s);
	while (!qu.empty())
	{
		S u = qu.top();   qu.pop();
		int ihu = inv_hash(u);
 
		for (int i = 0; i < 4; i++)
		{
			S v = u;
			v.x += dir[i][0];
			v.y += dir[i][1];
			if (v.x < 0 || v.x >= 3 || v.y < 0 || v.y >= 3) continue;
			v.maze[u.x][u.y] = u.maze[v.x][v.y];
			v.maze[v.x][v.y] = 'x';
			
			v.g += 1;  v.h = h(v); v.f = v.g + v.h; 
			int ihv = inv_hash(v); 
 
			if (vis[ihv])
				continue;
			vis[ihv] = 1;
			
			pre[ihv] = ihu; 
			if (i == 0) op[ihv] = 'd';
			else if (i == 1) op[ihv] = 'r';
			else if (i == 2) op[ihv] = 'u';
			else if (i == 3) op[ihv] = 'l';
			if (ihv == 0)
				return true;
			qu.push(v);
		}
	}
	return false;
}
 
inline bool inv_check()
{
	char str[10];
	int cnt = 0;
	for (int i = 0; i < 3; i++)
	for (int j = 0; j < 3; j++)
	{
		str[i * 3 + j] = s.maze[i][j];
		if (str[i * 3 + j] == 'x')continue;
		for (int k = i * 3 + j - 1; k >= 0; k--)
		{
			if (str[k] == 'x') continue;
			if (str[k]>str[i * 3 + j])
				cnt++;
		}
	}
	return !(cnt & 1);
}
 
char in[30];
char stk[100]; 
int main()
{
	while (cin.getline(in, 30))
	{
		for (int i = 0, x = 0, y = 0; in[i]; i++)
		{
			if (isdigit(in[i]) || in[i] == 'x')
			{
				s.maze[x][y] = in[i];
				if (in[i] == 'x') { s.x = x;  s.y = y; }
				y++;
				if (y == 3)
				{
					y = 0;
					x++;
				}
					
			}
		}
		if (!inv_check())
		{
			cout << "unsolvable" << endl;
			continue;
		}
		s.g = 0;  s.h = h(s);  s.f = s.h;

		int shash = inv_hash(s);
		if (shash == 0)
		{
			cout << endl;
			continue;
		}
 
		bfs();
 
		int top = -1, thash = 0;
		while (thash != shash)
		{
			stk[++top] = op[thash];
			thash = pre[thash];
		}
		for (int i = top; i >= 0; i--)
			cout << stk[i];
		cout << endl;
	}
	return 0;
}