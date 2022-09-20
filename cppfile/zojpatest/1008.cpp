//hdoj 1008
#include<cstdio>
using namespace std;

const int maxn=105;
int quest[maxn];

int main(){
    int n;
    while(scanf("%d",&n)==1&&n){
        int up=0,down=0;
        quest[0]=0;
        for(int i=1;i<=n;i++){
            scanf("%d",&quest[i]);
        }
        for(int i=1;i<=n;i++){
            if(quest[i]>quest[i-1]){
                up+=quest[i]-quest[i-1];
            }
            else{
                down+=quest[i-1]-quest[i];
            }
        }
        int result=up*6+down*4+5*n;
        printf("%d\n",result);
    }
    return 0;
}