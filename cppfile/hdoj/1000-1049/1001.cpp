#include<cstdio>
using namespace std;
int sum(int n){
    int s=0;
    for(int i=1;i<=n;i++){
        s+=i;
    } 
    return s;
}

int main(){
    int n;
    while(scanf("%d",&n)==1){
        printf("%d\n\n",sum(n));
    }
    return 0;
}