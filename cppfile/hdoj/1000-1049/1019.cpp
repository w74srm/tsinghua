#include<cstdio>
using namespace std;

int gcd(int a,int b){
    return b==0?a:gcd(b,a%b);
}

int main(){
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        int k,LCM;
        scanf("%d%d",&k,&LCM);
        for(int j=1;j<k;j++){
            int temp;
            scanf("%d",&temp);
            LCM=(LCM/gcd(LCM,temp))*temp;
        }
        printf("%d\n",LCM);
    }
    return 0;
}