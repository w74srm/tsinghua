#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
 
const int maxn = 1000;
int N, M, K;
vector<int> G[maxn];
bool vis[maxn] = { false };
void DFS(int u)
{
	vis[u] = true;
	for (int i = 0; i < G[u].size(); i++)
	{
		int t = G[u][i];
		if (!vis[t])
		{
			DFS(t);
		}
	}
}
int DFSTrave(vector<int>*G,int destroy,bool*vis)
{
	vis[destroy] = true;
	int count = -1;
	for (int i = 0; i < N; i++)
	{
		if (!vis[i])
		{
			DFS(i);
			count++;
		}
	}
	return count;
}
int main()
{
	scanf("%d %d %d", &N, &M, &K);
	int u,v;
	for (int i = 0; i < M; i++)
	{
		scanf("%d %d", &u,&v);
		G[u-1].push_back(v-1);
		G[v-1].push_back(u-1);
	}
	int destroy;
	for (int i = 0; i < K; i++)
	{
		scanf("%d", &destroy);
		printf("%d\n", DFSTrave(G, destroy-1, vis));
		fill(vis, vis + maxn, false);
	}
	return 0;
}