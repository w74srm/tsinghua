#include <cstdio>
#include <algorithm>
using namespace std;
struct Rate 
{
	double javaBean;
	double catFood;
	double rat;
}rate[1000];
bool cmp(const Rate &a,const Rate &b)
{
	if(a.rat>b.rat)
		return true;
	else
		return false;
}
int main(){
    double M;
    int N;
    while(scanf("%lf%d",&M,&N)==2&&M!=-1&&N!=-1){
        for(int i=0;i<N;i++){
            scanf("%lf%lf",&rate[i].javaBean,&rate[i].catFood);
            rate[i].rat=rate[i].javaBean/rate[i].catFood;
        }
        sort(rate,rate+N,cmp);
        int cnt=0;
        double result=0;
        while(M>0&&cnt<N){
            if(M>=rate[cnt].catFood){
                result+=rate[cnt].javaBean;
            }
            else{
                result+=rate[cnt].javaBean*(M/rate[cnt].catFood);
            }
            M-=rate[cnt].catFood;
            cnt++;
        }
        printf("%.3lf\n",result);
    }
    return 0;
}