#include<cstdio>
#include<cmath>
#include"point.h"
using namespace std;

double torad(double ang){
    return (ang/PI)*180;
}

int main(){
    int T;
    Point P[2500],ch[2500];
    scanf("%d",&T);
    while(T--){
        int n,pc=0;
        double area1=0;
        scanf("%d",&n);
        for(int i=0;i<n;i++){
            double x,y,w,h,j,ang;
            scanf("%lf%lf%lf%lf%lf",&x,&y,&w,&h,&j);
            Point o(x,y);
            ang=-torad(j);
            P[pc++]=o+Rotate(Vector(-w/2,-h/2),ang);
            P[pc++]=o+Rotate(Vector(w/2,-h/2),ang);
            P[pc++]=o+Rotate(Vector(-w/2,h/2),ang);
            P[pc++]=o+Rotate(Vector(w/2,h/2),ang);
            area1+=w*h;
        }
        int m=ConvexHull(P,pc,ch);
        double area2=PolygonArea(ch,m);
        printf("%.11f %%\n",area1*100/area2);
    }
    return 0;
}