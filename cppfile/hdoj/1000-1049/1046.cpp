#include<cstdio>
using namespace std;

int main(){
    int T,n,m;
    scanf("%d",&T);
    for(int kase=1;kase<=T;kase++){
        scanf("%d%d",&n,&m);
        float res=m*n;
        if(m%2==1&&n%2==1){
            res=res+0.41;
        }
        printf("Scenario #%d:\n%.2f\n\n",kase,res);
    }
    return 0;
}