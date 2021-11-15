#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<ctime>
#include<algorithm>
#include<cstring>
#define eps 1e-3
#define PI acos(-1.0)
#define inf 0x3f3f3f3f
using namespace std;
const int NUM=30;
double MAX(double a,double b){
	return a>b?a:b;
}
double MIN(double a,double b){
	return a<b?a:b;
}
double dist(double x1,double y1,double x2,double y2){
	return sqrt((x2-x1)*(x2-x1)+(y2-y1)*(y2-y1));
}
struct point{
	double x,y;
}A[1010],B[1010];
double d[1010];
int main()
{
	int t,X,Y,M,i,j,k,ans;
	srand((unsigned)time(NULL));
	scanf("%d",&t);
	while(t--){
		scanf("%d%d%d",&X,&Y,&M);
		for(i=0;i<M;++i){
			scanf("%lf%lf",&A[i].x,&A[i].y);
		}
		for(i=0;i<NUM;++i){//随机选取NUM个可能点 
			B[i].x=double(rand()%1000+1)/1000.0*X;
			B[i].y=double(rand()%1000+1)/1000.0*Y;
			d[i]=inf;
			for(j=0;j<M;++j){//确定选取的点与陷阱相距的最短距离 
				d[i]=MIN(d[i],dist(B[i].x,B[i].y,A[j].x,A[j].y));
			}
		}
		double dmax=double(MAX(X*1.0,Y*1.0))/sqrt(1.0*M);//取相距最大距离； 
		while(dmax>eps){
			for(i=0;i<NUM;++i){
				double xx=B[i].x,yy=B[i].y;
				for(j=0;j<NUM;++j){
					double angle=double(rand()%1000+1)/1000.0*2.0*PI;
					double mx=dmax*cos(angle);//以dmax为半径向外扩展随机寻找NUM个新点 
					double my=dmax*sin(angle);
					double newx=xx+mx,newy=yy+my;
					if(newx<eps||newx>X||newy<eps||newy>Y)continue;
					double temp=inf;
					for(k=0;k<M;++k){
						temp=MIN(temp,dist(newx,newy,A[k].x,A[k].y));
					} 
					if(temp>d[i]){//当该新点最小距离大则更新 
						d[i]=temp;B[i].x=newx;B[i].y=newy;
					}
				}
			}
			dmax*=0.8;//降温退火 
		}
		double dmin=-1;
		for(i=0;i<NUM;++i){
			if(d[i]>dmin){
				ans=i;dmin=d[i];
			}
		}
		printf("The safest point is (%.1lf, %.1lf).\n",B[ans].x,B[ans].y);
	}
	return 0;
}