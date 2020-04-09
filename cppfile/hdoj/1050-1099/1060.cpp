#include<cstdio>
#include<cmath>
using namespace std;

int main(){
    int T;
    scanf("%d",&T);
    while(T--){
        double n;
        scanf("%lf",&n);
        double m=n*log10(n*1);
        m-=floor(m);
        int res=(int)pow(10,m);
        printf("%d\n",res);
    }
    return 0;
}