#include <iostream>
#include <cmath>
using namespace std;
 
char maze[9][9];
int starti,startj,endi,endj,t,n,m;
int flag;
int direction[4][2]={{0,1},{0,-1},{1,0},{-1,0}};
             
 
void DFS(int px,int py,int time)
{
    int i;
    if(flag==1)return;
    if(maze[px][py]=='X')return;
    if(px==endi&&py==endj&&time==t){flag=1;return;}
    if(px<1||px>n||py<1||py>m)return; 
    if(time>t)return;
    
    for(i=0;i<4;i++)
    {
        maze[px][py]='X';
        DFS(px+direction[i][0],py+direction[i][1],time+1);
        maze[px][py]='.';
        if(flag==1)return;
    }
    
}
 
int main()
{
    int i,j,block;
    char temp;
    while(cin>>n>>m>>t)
    {
        block=0;
        flag=0;
        if(n==0&&m==0&&t==0)break;
       
        for(i=1;i<=n;i++)
        {
          for(j=1;j<=m;j++)
          {
              cin>>maze[i][j];
            
              if(maze[i][j]=='S'){starti=i;startj=j;continue;}
              if(maze[i][j]=='X'){block++;continue;}
              if(maze[i][j]=='D'){endi=i;endj=j;}
          }
        }
          if(t>(n*m-block)) 
          {
              cout<<"NO"<<endl;
              continue;
          }
          if((endi+starti+startj+endj+t)%2==1)
          {
              cout<<"NO"<<endl;
              continue;
          }
          
          DFS(starti,startj,0);
          if(flag==1)cout<<"YES"<<endl;
          else cout<<"NO"<<endl;
          
    }
 
    return 0;
}