#include<vector>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
struct name
{
	char name1[5];
	bool operator<(name na)
	{
		return strcmp(name1, na.name1) <= 0;
	}
};

int main()
{
	int n, k;
	scanf("%d %d", &n, &k);
	name na; int t,ni;
	vector<vector<name> >v;
	vector<name>vn;
	for (int i = 0; i <= k; i++)
	{
		v.push_back(vn);
	}
	for (int x = 0; x < n; x++)
	{
		scanf("%s %d", na.name1, &t);
		for (int j = 0; j < t; j++)
		{
			scanf("%d", &ni);
			v[ni].push_back(na);
		}
	}
	for (int i = 1; i <= k; i++)
	{
		printf("%d %d\n", i, v[i].size());
		sort(v[i].begin(), v[i].end());
		for (int j = 0; j < v[i].size(); j++)
		{
			printf("%s\n", v[i][j].name1);
		}
	}
	return 0;
}