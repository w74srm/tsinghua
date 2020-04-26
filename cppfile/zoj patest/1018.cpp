#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int C, N, S, M;
vector<int> current;
vector<vector<int> > adjMatrix;
vector<bool> reach;
int minTake, minBack, minLen;
vector<int> ans, temp;

void DFS(int s, int take, int back, int length)
{
	if (s == S)
	{
		if (length < minLen || (length == minLen && take < minTake) ||
			(length == minLen && take == minTake && back < minBack))
		{
			ans = temp;
			minLen = length;
			minTake = take;
			minBack = back;
		}
		return;
	}
	for (int i = 1; i < N + 1; i++)
	{
		if (reach[i] == false && adjMatrix[s][i] != 0)
		{
			reach[i] = true;
			temp.push_back(i);
			int addTake = max(C / 2 - current[i], 0);
			if (back > 0)
				addTake = max(0, addTake - back);
			int newBack = max(back + current[i] - C / 2, 0);
			DFS(i, take + addTake, newBack, length + adjMatrix[s][i]);
			reach[i] = false;
			temp.pop_back();
		}
	}
}
int main()
{
	cin >> C >> N >> S >> M;
	current.resize(N + 1);
	adjMatrix.assign(N + 1, vector<int>(N + 1));
	reach.assign(N + 1, false);
	for (int i = 1; i < N+1; i++)
	{
		cin >> current[i];
	}
	for (int i = 0; i < M; i++)
	{
		int s1, s2, time;
		cin >> s1 >> s2 >> time;
		adjMatrix[s1][s2] = adjMatrix[s2][s1] = time;
	}
	minTake = minBack = minLen = 100000000;
	DFS(0, 0, 0, 0);
	printf("%d 0", minTake);
	for (int i = 0; i < ans.size(); i++) {
		printf("->%d", ans[i]);
	}
	printf(" %d", minBack);
	return 0;
}