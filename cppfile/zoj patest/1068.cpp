#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int cnt[101]={0};
bool flag=false;
void dfs(int curr,int left,vector<int>& v)
{
	if(left==0) 
	{
			printf("%d",v[0]);
		for(int i=1;i<v.size();i++)
			printf(" %d",v[i]);
		printf("\n");
		flag=true;	
		return;
	}
	if(curr>left||flag) 
		return;	
	int i=0;
	for(i=curr;i<=left&&!flag;i++)
		if(cnt[i]>0)
		{
			v.push_back(i);
			cnt[i]--;
			dfs(i,left-i,v); 
			cnt[i]++;
			v.pop_back();
		}
}
int main(){
    int n,m,t;
    cin>>n>>m;
    for(int i=0;i<n;i++)
    {
    	scanf("%d",&t);
    	if(t<=100)
    	cnt[t]++;
    }
	vector<int> ans;
	dfs(1,m,ans);
	if(!flag)
		printf("No Solution\n");
    return 0;
}
