#include<cstdio>
#include<cmath>
using namespace std;

int main(){
    int T;
    scanf("%d",&T);
    while(T--){
        long n;
        scanf("%ld",&n);
        int m=n%10;
        int t=1;
        for(int i=0;i<=(n-1)%4;i++) t*=m;
        printf("%d\n",t%10);
    }
    return 0;
}