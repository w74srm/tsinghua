#include<cstdio>
#include<cstring>
using namespace std;

const int maxn=1000000;
int a[maxn];

int mode(int left,int right,int num){
    int cnt=1;
    for(int i=left+1;i<right;i++){
        if(a[i]==a[left]) cnt++;
    }
    if(cnt>=num) return a[left];
    else return mode(left+1,right,num);
}

int main(){
    int n;
    while(scanf("%d",&n)==1){
        memset(a,0,sizeof(a));
        for(int i=0;i<n;i++){
            scanf("%d",&a[i]);
        }
        printf("%d\n",mode(0,n,(n+1)/2));
    }
    return 0;
}