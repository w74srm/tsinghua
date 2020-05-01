#include<cstdio>
#include<algorithm>
#include<vector>
#include<map>
using namespace std;
 
int main()
{
	int N;
	scanf("%d", &N);
	vector<int> v; int t;
	for (int i = 0; i < N; i++)
	{
		scanf("%d", &t);
		v.push_back(t);
	}
	scanf("%d", &N);
	for (int i = 0; i < N; i++)
	{
		scanf("%d", &t);
		v.push_back(t);
	}
	sort(v.begin(), v.end());
	printf("%d", v[(v.size() - 1) >> 1]);
	return 0;
}