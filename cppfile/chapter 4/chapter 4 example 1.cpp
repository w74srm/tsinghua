#include"point.h"
#include<cstdio>
using namespace std;

Point getD(Point A,Point B,Point C){
    Vector v1=C-B;
    double a1=Angle(A-B,v1);
    v1=Rotate(v1,a1/3);

    Vector v2=B-C;
    double a2=Angle(A-C,v2);
    v2=Rotate(v2,-a2/3);
    
    return GetLineIntersection(B,v1,C,v2);
}

int main(){
    int T;
    Point A,B,C,D,E,F;
    scanf("%d",&T);
    while(T--){
        A=read_point();
        B=read_point();
        C=read_point();
        D=getD(A,B,C);
        E=getD(B,C,A);
        F=getD(C,A,B);
        printf("%.61f %.61f %.61f %.61f %.61f %.61f",D.x,D.y,E.x,E.y,F.x,F.y);
    }
    return 0;
}