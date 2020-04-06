#include<cstdio>
using namespace std;

int main(){
    int n,u,d;
    while(scanf("%d%d%d",&n,&u,&d)==3&&n){
        int h=0,res=0;
        while(h+u<n){
            h+=(u-d);
            res+=2;
        }
        printf("%d\n",res+1);
    }
    return 0;
}