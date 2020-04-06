#include<cstdio>
#include<algorithm>
using namespace std;

const int maxn=1000010;
int c[maxn];

void initC(int m,int n){
    for(int i=m;i<=n;i++){
        int cnt=1;
        int temp=i;
        while(temp!=1){
            if(temp%2==1) temp=3*temp+1;
            else temp/=2;
            cnt++;
            if(temp<i&&temp>=m){
                cnt+=c[temp];
                cnt--;
                break;
            }
        }
        c[i]=cnt;
    }
}

int main(){
    int i,j;
    while(scanf("%d%d",&i,&j)==2){
        int m=i,n=j;
        if(i>j) swap(i,j);
        initC(i,j);
        int max=0;
        for(int k=i;k<=j;k++){
            if(c[k]>max) max=c[k];
        }
        printf("%d %d %d\n",m,n,max);
    }
    return 0;
}