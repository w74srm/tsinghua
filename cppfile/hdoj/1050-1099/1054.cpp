#include<stdio.h>
#include<cstring>
#include<vector>
using namespace std;
#pragma comment(linker,"/STACK:102400000,102400000")
#define MAX   1505
int visit[MAX];
int ret[MAX];
vector<int>map[MAX];
int find(int cur )
{
     for(int i=0;i<map[cur].size();i++)
     {
          int j=map[cur][i];
          if(!visit[j])
          {
               visit[j]=1;
               if(ret[j]==-1||find(ret[j]))
               {
                    ret[j]=cur;
                    return 1;
               }
          }
     }
     return 0;
}
int main()
{
     int n,x,m,y;
     while(scanf("%d",&n)!=EOF)
     {
          for(int i=0;i<n;i++)map[i].clear();
          for(int i=0;i<n;i++)
          {
               scanf("%d:(%d)",&x,&m);
               for(int j=0;j<m;j++)
               {
                    scanf("%d",&y);
                    map[x].push_back(y);
                    map[y].push_back(x);
               }
          }
          int sum=0;
          memset(ret,-1,sizeof(ret));
          for(int i=0;i<n;i++)
          {
               memset(visit,0,sizeof(visit));
               sum+=find(i);
          }
          printf("%d\n",sum/2);
     }
   return 0;
}