#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;

const int maxn=1010;
const int maxv=10010;
const int inf = 99999999;
int value[maxn], volume[maxn], FF[maxv];

int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        int E,F,n,v;
        scanf("%d%d%d",&E,&F,&n);
        v=F-E;
        for(int i=1;i<=n;i++)
            scanf("%d%d",&value[i],&volume[i]);
        for(int i=0;i<=v;i++)
            FF[i]=inf;
        FF[0]=0;
        for(int i=1;i<=n;i++)
            for(int j=volume[i];j<=v;j++)
                        FF[j]=min(FF[j],FF[j-volume[i]]+value[i]);
 
        if(FF[v]!=inf)
            cout<<"The minimum amount of money in the piggy-bank is "<<FF[v]<<"."<<endl;
        else
            cout<<"This is impossible."<<endl;
    }
    return 0;
}