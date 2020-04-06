//zui chang shang sheng zi xu lie
#include<stdio.h>
#include<algorithm>
using namespace std;
const int N=500010;
struct road{
	int x,y;
}arr[N];
bool cmp(road a,road b){
	return a.x<b.x;
}
int bsearch(int A[],int n,int x){
	int left=0,right=n-1,mid;
	while(left<=right){
		mid=(left+right)/2;
		if(A[mid]>=x)
			right=mid-1;
		else left=mid+1;
	}
	return left;
}
int main(){
	int n;int dp[N];int index=0,tmp;
	int count=0;
	while(scanf("%d",&n)!=EOF){
		count++;
		for(int i=0;i<n;i++)
			scanf("%d%d",&arr[i].x,&arr[i].y);
		sort(arr,arr+n,cmp);
		dp[0]=arr[0].y;index=0;
		for(int j=1;j<n;j++){
			tmp=bsearch(dp,index+1,arr[j].y);
			dp[tmp]=arr[j].y;
			if(tmp>index)
				index=tmp;
		}
		if(index==0)
			printf("Case %d:\nMy king, at most %d road can be built.\n\n",count,index+1);
		else
			printf("Case %d:\nMy king, at most %d roads can be built.\n\n",count,index+1);
	}
	return 0;
}