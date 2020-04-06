#include<iostream>
#include <cstdio>
using namespace std;
const int max_n=1010;
int pre[max_n];
int nex[max_n];
int c[max_n];
int num[max_n];
int visit[max_n];
int sum[max_n];
int father[max_n];
int n,r;
int find_max()
{ 
    double imax=0;
    int bh=-1;
    for(int i=1; i<=n; i++) {
        if(imax<(sum[i]*1.0)/num[i]&&visit[i]==0) {
            imax=(sum[i]*1.0)/num[i];
            bh=i;
        }
    }
    return bh;
}
void make(int x)
 { 
    int i;
    for(i = father[x]; pre[i] != -1; i = pre[i]);
    sum[i]+=sum[x];
    num[i]+=num[x];
    for(i= father[x]; nex[i] != -1; i = nex[i]);
    nex[i]=x;
    pre[x]=i;
    visit[x]=1;
}
int main()
{
 
    while(scanf("%d %d",&n,&r),n&&r) {
        for(int i=1; i<=n; i++) {
            scanf("%d",&c[i]);
            sum[i]=c[i];
            visit[i] =0;
            pre[i] = nex[i] = -1;
            num[i] = 1;
        }
        for(int i = 1; i < n; i++) {
            int a,b;
            scanf("%d %d",&a,&b);
            father[b] = a;
        }
        int d;
        visit[r]=1;
        while(1) {
            d=find_max();
            if(d==-1)break;
            make(d);
        }
        int ans=0,cnt=1;
        for(int i=r; i!=-1; i=nex[i]) {
            ans+=cnt*c[i];
            cnt++;
        }
        printf("%d\n",ans);
    }
    return 0;
}