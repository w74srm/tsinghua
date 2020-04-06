#include<cstdio>
using namespace std;

int main(){
    double len;
    while(scanf("%lf",&len)&&len){
        double test=0;
        int cnt=0;
        while(test<len){
            cnt++;
            test+=(1/(double)(cnt+1));
        }
        printf("%d card(s)\n",cnt);
    }
    return 0;
}