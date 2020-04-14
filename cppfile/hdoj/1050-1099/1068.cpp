//最大独立集=所有点数-最大匹配数，这一道题的最大匹配数会有重复，所以要除以2
#include<iostream>
#include<cstring>
#define maxn 1005
using namespace std;
int n;
int map[maxn][maxn],used[maxn],match[maxn];
void init(){
    memset(map,0,sizeof(map));
    int x,k,y;
    for (int i=0;i<n;i++){
        scanf("%d: (%d) ",&x,&k);
        for (int j=0;j<k;j++){
            cin >> y;
            map[x][y]=1;
        }
    }
    return ;
}
int dfs(int x){
    for (int i=0;i<n;i++){
        if (map[i][x] && !used[i]){
            used[i]=1;
            if (match[i]==-1 || dfs(match[i])){
                match[i]=x;
                return 1;
            }
        }
    }
    return 0;
}
int main(){
    while (cin >> n && n){
        init();
        int ans=0;
        memset(match,-1,sizeof(match));
        for (int i=0;i<n;i++){
            memset(used,0,sizeof(used));
            if (dfs(i)) ans++;
        }
        cout << n-ans/2 << endl;
    }
    return 0;
}