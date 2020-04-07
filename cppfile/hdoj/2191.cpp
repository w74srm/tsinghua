#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
const int maxn=1005;
const int maxv=1006;
int volume[maxn];
int value[maxn];
int number[maxn];
int f[maxn];
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int v,n;
		scanf("%d%d",&v,&n);
		for(int i=1;i<=n;i++)
		{
			scanf("%d%d%d",&volume[i],&value[i],&number[i]);
		}
		memset(f,0,sizeof(f));
		for(int i=1;i<=n;i++)
			for(int k=1;k<=number[i];k++)
				for(int j=v;j>=volume[i];j--)
					f[j]=max(f[j],f[j-volume[i]]+value[i]);
		cout<<f[v]<<endl;
 
	}
	return 0;
}