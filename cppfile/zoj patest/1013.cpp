#include<iostream>
#include<cstring>
using namespace std;

int vis[1005],map[1005][1005];

void dfs(int a,int n,int c){
    for(int i=1;i<=n;i++){
        vis[a]=1;
        if(map[a][i]==1&&vis[i]==0&&i!=c){
            dfs(i,n,c);
        }
    }
}

int main(){
    int N,M,K;
    cin>>N>>M>>K;
    int start,end;
    for(int i=0;i<M;i++){
        cin>>start>>end;
        map[start][end]=1;
        map[end][start]=1;
    }
    for(int kase=0;kase<K;kase++){
        int res=0;
        int c;
        cin>>c;
        memset(vis,0,sizeof(vis));
        for(int i=1;i<=N;i++){
            if(vis[i]==0&&i!=c){
                dfs(i,N,c);
                res++;
            }
        }
        cout<<res-1<<endl;
    }
    return 0; 
}