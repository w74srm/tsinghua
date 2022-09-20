//dijkstra
#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<climits>
#include<string.h>
using namespace std;
const int MAX=0x3f3f3f3f;
 
 
int map[555][555];
int value[555][555];
int dis[555];
int val[555];
int vis[555];
int pass[555];
 
void dfs(int v)
{
    if(v==pass[v])
    {
        printf("%d ",v);
        return;
    }
    dfs(pass[v]);
    printf("%d ",v);
    return ;
}
 
void Dijkstra(int s,int n)
{
    int i,j,k,min;
    dis[s]=0;
    val[s]=0;
    pass[s]=s;
 
    for(i=0; i<n; i++)
    {
        min=MAX;
        k=-1;
        for(j=0; j<n; j++)
        {
            if(vis[j]==0&&min>dis[j])
            {
                min=dis[j];
                k=j;
            }
        }
        if(k==-1)
            return ;
        vis[k]=1;
        for(j=0; j<n; j++)
        {
            if(vis[j]==0&&map[k][j]<MAX)
            {
                if(dis[j]>dis[k]+map[k][j])
                {
                    pass[j]=k;
                    dis[j]=dis[k]+map[k][j];
                    val[j]=val[k]+value[k][j];
                }
                else if(dis[j]==dis[k]+map[k][j]&&val[j]>val[k]+value[k][j])
                {
                    pass[j]=k;
                    val[j]=val[k]+value[k][j];
                }
            }
        }
    }
    return ;
}
 
int main()
{
    int n,m;
    int s,t;
    while(~scanf("%d%d%d%d",&n,&m,&s,&t))
    {
        int a,b,d,p;
        memset(vis,0,sizeof(vis));
        memset(map,MAX,sizeof(map));
        memset(value,MAX,sizeof(value));
        memset(dis,MAX,sizeof(dis));
        memset(pass,0,sizeof pass);
        for(int i=0; i<m; i++)
        {
            scanf("%d%d%d%d",&a,&b,&d,&p);
            map[a][b]=d;
            map[b][a]=d;
            value[a][b]=p;
            value[b][a]=p;
        }
        Dijkstra(s,n);
        dfs(t);
        printf("%d %d\n",dis[t],val[t]);
    }
    return 0;
}