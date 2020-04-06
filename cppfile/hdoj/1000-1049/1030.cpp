#include<cstdio>
#include<cmath>
using namespace std;

const int maxn=1000000001;

int main(){
    int n,m;
    while(scanf("%d%d",&n,&m)==2){
        int nLayer=ceil(sqrt(n));
        int mLayer=ceil(sqrt(m));
        if(nLayer==mLayer) printf("%d\n",abs(n-m));
        else{
            int nX=(nLayer*nLayer-n)/2;
            int mX=(mLayer*mLayer-m)/2;
            int nY=(n-(nLayer*nLayer-2*nLayer+2))/2;
            int mY=(m-(mLayer*mLayer-2*mLayer+2))/2;
            int result=abs(nX-mX)+abs(nY-mY)+abs(nLayer-mLayer);
            printf("%d\n",result);
        }
    }
    return 0;
}