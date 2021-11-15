#include <iostream>
#include <cstring>
using namespace std;
 
bool key[105][105], lock[10005][1005]; //钥匙，锁
bool visit[10005][1005];
int R, C; //钥匙的边长
int D, W; //锁的边长
 
bool in(int y)
{
	if (y >= 0 && y < W)
		return true;
	else
		return false;
}
 
bool door(int x, int y)
{
	for (int i = 0; i < R; i++)
	{
		for (int j = 0; j < C; j++)
			if (key[i][j] && lock[i + x][j + y])
				return false;
	}
	return true;
}
 
int main()
{
	int T;
	cin >> T;
	while (T--)
	{
		memset(key, 0, sizeof(key));
		memset(lock, 0, sizeof(lock));
		memset(visit, 0, sizeof(visit));
 
		char str[1005];
		cin >> R >> C;
		for (int i = 0; i < R; i++) //输入钥匙
		{
			cin >> str;
			for (int j = 0; j < C; j++)
			{
				if (str[j] == '#')
					key[i][j] = 1;
			}
		}
 
		cin >> D >> W;
		D += R;
		for (int i = R; i < D; i++) //输入锁
		{
			cin >> str;
			for (int j = 0; j < W; j++)
			{
				if (str[j] == '#')
					lock[i][j] = 1;
			}
		}
 
		for (int i = 0; i < W; i++)
			visit[0][i] = 1;
 
		int i, j;
		for (i = 1; i < D; i++)
		{
			bool flag = false;
			for (j = 0; j <= W - C; j++)
			{
				if (!visit[i][j] && (visit[i - 1][j] || (in(j - 1) && visit[i][j - 1]) || (in(j + 1) && visit[i][j + 1])))
				{
					if (door(i, j))
					{
						flag = true;
						visit[i][j] = 1;
						if (j > 0 && !visit[i][j - 1])
							j -= 2;
					}
				}
			}
			if (flag == false)
				break;
		}
 
		if (i == D)
			cout << "The key can fall through." << endl;
		else
			cout << "The key falls to depth " << i - 1 << "." << endl;
	}
	return 0;
}