#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

int main(){
    int T,n,v;
    int weight[1002],value[1002];
    int f[1002];
    scanf("%d",&T);
    while(T--){
        scanf("%d%d",&n,&v);
        memset(f,0,sizeof(f));
        for(int i=0;i<n;i++){
            scanf("%d",&weight[i]);
        }
        for(int i=0;i<n;i++){
            scanf("%d",&value[i]);
        }
        for(int i=0;i<n;i++){
            for(int j=v;j>=value[i];j--){
                f[j]=max(f[j],f[j-value[i]]+weight[i]);
            }
        }
        printf("%d\n",f[v]);
    }
    return 0;
}