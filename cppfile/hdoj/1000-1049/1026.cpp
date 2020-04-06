#include <iostream>
#include <cstring>
#include <queue>
using namespace std;
 
const int N = 101;
char map[N][N];
int dis[4][2] = { { 1, 0 }, { -1, 0 }, { 0, 1 }, { 0, -1 } };
int n, m;
struct grid
{
	int x, y;
	int time;
	friend bool operator<(grid a, grid b)
	{
		return a.time>b.time;
	}
};
grid path[N][N];
 
bool BFS(int &time);
void showPath(int time, int x, int y);
 
bool BFS(int &time)
{
	priority_queue<grid> q;
	grid start, temp;
	start.x = 0;
	start.y = 0;
	start.time = 0;
	q.push(start);
	while (!q.empty())
	{
		start = q.top();
		q.pop();
		if (start.x == n - 1 && start.y == m - 1)
		{
			time = start.time;
			return true;
		}
		temp = start;
		for (int i = 0; i < 4; i++)
		{
			start.x = temp.x + dis[i][0];
			start.y = temp.y + dis[i][1];
			start.time = temp.time + 1;
			if (start.x < 0 || start.y < 0 || start.x >= n || start.y >= m || map[start.x][start.y] == 'X')
				continue;
			path[start.x][start.y] = temp;
			path[start.x][start.y].time = 0;
			if (map[start.x][start.y] != '.')
			{
				start.time += map[start.x][start.y] - '0';
				path[start.x][start.y].time = map[start.x][start.y] - '0';
			}
			map[start.x][start.y] = 'X';
			q.push(start);
		}
	}
	return false;
}
 
void showPath(int time, int x, int y)
{
	if (time == 0)
		return;
	time -= path[x][y].time;
	showPath(time - 1, path[x][y].x, path[x][y].y); 
	cout << time++ << "s:(" << path[x][y].x << "," << path[x][y].y << ")->(" << x << "," << y << ")" << endl;
	while (path[x][y].time--)
		cout << time++ << "s:FIGHT AT (" << x << "," << y << ")" << endl;
}
 
int main()
{
	int time;
	while (cin >> n >> m)
	{
		time = 0;
		memset(path, 0, sizeof(path));
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				cin >> map[i][j];
			}
		}
		if (BFS(time))
		{
			cout << "It takes " << time << " seconds to reach the target position, let me show you the way." << endl;
			showPath(time, n - 1, m - 1);
		}
		else
		{
			cout << "God please help our poor hero." << endl;
		}
		cout << "FINISH" << endl;
	}
	return 0;
}