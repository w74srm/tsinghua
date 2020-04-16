#include <iostream>
#include<cstring>
using namespace std;
 
int n,m,c1,c2;
int e[505][505];
int renshu[505];
int book[505];
int cnt,maxnum,mindis;
 
void dfs(int x,int num,int dis)
{
    if(x==c2)
    {
        if(dis<mindis)
        {
            cnt=1;
            maxnum=num;
            mindis=dis;
        }
        else if (dis==mindis)
        {
            cnt++;
            if(num>maxnum)
            {
                maxnum=num;
            }
        }
        return;
    }
    for(int i=0;i<n;i++)
    {
        if(book[i]==0&&e[x][i]!=0x3f3f3f3f)
        {
            book[i]=1;
            dfs(i,num+renshu[i],dis+e[x][i]);
            book[i]=0;
        }
    }
}
 
int main()
{
    int a,b,c;
    memset(e,0x3f,sizeof(e));
    memset(book,0,sizeof(book));
    mindis=0x3f3f3f3f;
 
    cin>>n>>m>>c1>>c2;
    for(int i=0;i<n;i++)
    {
        cin>>renshu[i];
    }
    for(int i=0;i<m;i++)
    {
        cin>>a>>b>>c;
        e[a][b]=c;
        e[b][a]=c;
    }
    book[c1]=1;
 
    dfs(c1,renshu[c1],0);
    cout<<cnt<<" "<<maxnum<<endl;
    return 0;
}