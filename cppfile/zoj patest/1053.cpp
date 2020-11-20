#include<cstdio>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;
const int maxn = 100;
int N, M,S;
vector<int> children[maxn];
int weight[maxn];
vector<int> path;
vector<vector<int> > paths;
void DFS(int root, int sumweight,vector<int> path)
{
	if (!children[root].size())
	{
		if (sumweight == S)
			paths.push_back(path);
		return;
	}
	for (int i = 0; i < children[root].size(); i++)
	{
		int t = children[root][i];
		vector<int> temppath = path;
		temppath.push_back(weight[t]);
		DFS(t, sumweight + weight[t],temppath);
	}	
}
bool cmp(vector<int> v1, vector<int> v2)
{
	bool flag = false;
	for (int i = 0; i < min(v1.size(), v2.size()); i++)
	{
		if (v1[i] > v2[i])
		{
			flag = true;
			break;
		}
		else if (v1[i] < v2[i])
		{
			flag = false;
			break;
		}
	}
	return flag;
}
int main()
{
	scanf("%d %d %d", &N, &M, &S);
	for (int i = 0; i < N; i++)
	{
		scanf("%d", &weight[i]);
	}
	int father, k, child;
	for (int i = 0; i < M; i++)
	{
		scanf("%d %d", &father, &k);
		while (k--)
		{
			scanf("%d", &child);
			children[father].push_back(child);
		}
	}
	path.push_back(weight[0]);
	DFS(0, weight[0], path);
	sort(paths.begin(), paths.end(), cmp);
	for (int i = 0; i < paths.size(); i++)
	{
		for (int j = 0; j < paths[i].size(); j++)
		{
			printf("%d", paths[i][j]);
			if (j != paths[i].size() - 1)
				printf(" ");
			else
				printf("\n");
		}
	}
	return 0;
}