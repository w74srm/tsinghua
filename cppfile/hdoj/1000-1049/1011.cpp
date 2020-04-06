#include <iostream>
#include <cstring>
#include <vector>
using namespace std;
int N,M;
struct Room
{
	int cost;
	int possibility;
};
Room room[105];
int dp[105][105];
vector<int> connection[105];
void dfsTreeDp(int p,int pre)
{
	int i,j,k;
	for(i=room[p].cost;i<=M;i++)
		dp[p][i]=room[p].possibility;
	int num=connection[p].size();
	for(i=0;i<num;i++)
	{
		int v=connection[p][i];
		if(v==pre) continue;
		dfsTreeDp(v,p);
		
		for(j=M;j>=room[p].cost;j--)
			for(k=1;k<=j-room[p].cost;k++)
				if(dp[p][j]<dp[p][j-k]+dp[v][k])  
                {
                    dp[p][j]=dp[p][j-k]+dp[v][k];  
                } 
	}
}
 
int main()
{
	int i,start,end;
	int bug;
	while((cin>>N>>M)&&(M!=-1)&&(N!=-1))
	{
		for(i=0;i<N;i++)
		{
			cin>>bug>>room[i].possibility;
			room[i].cost=(bug+19)/20;
		}
		for(i=0;i<N;i++)
		{
			connection[i].clear();
		}
		for(i=0;i<N-1;i++)
		{
			cin>>start>>end;
			connection[start-1].push_back(end-1);
			connection[end-1].push_back(start-1);
		}
		if(M==0)
		{
			cout<<"0"<<endl;
			continue;
		}
		memset(dp, 0, sizeof(dp)); 
		dfsTreeDp(0,-1);
		cout<<dp[0][M]<<endl; 
	}
}