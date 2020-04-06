#include<cmath>
#include<algorithm>
#include<cstdio>
#include<vector>
using namespace std;
#define PI 3.1415926

struct Point{
    double x,y;
    Point(double x=0,double y=0):x(x),y(y){}
};

typedef Point Vector;

struct Line{
    Point P;
    Vector v;
    double ang;
    Line(){}
    Line(Point P,Vector v):P(P),v(v){ang = atan2(v.y,v.x);}
    bool operator < (const Line& L) const{
        return ang<L.ang;
    }
};

struct Circle{
    Point c;
    double r;
    Circle(Point c,double r):c(c),r(r){}
    Point point (double a){
        return Point(c.x+cos(a)*r,c.y+sin(a)*r);
    }
};

Vector operator + (Vector A,Vector B){return Vector(A.x+B.x,A.y+B.y);}

Vector operator - (Vector A,Vector B){return Vector(A.x-B.x,A.y-B.y);}

Vector operator * (Vector A,double p){return Vector(A.x*p,A.y*p);}

Vector operator / (Vector A,double p){return Vector(A.x/p,A.y/p);}

bool operator<(const Point& a, const Point& b){
    return a.x<b.x||(a.x==b.x&&a.y<b.y);
}

const double eps=1e-10;
int dcmp(double x){
    if(fabs(x)<eps) return 0;
    else return x<0?-1:1;
}

bool operator==(const Point& a,const Point &b){
    return dcmp(a.x-b.x)==0&&dcmp(a.y-b.y)==0;
}

Point read_point(){
    double x,y;
    scanf("%lf%lf",&x,&y);
    return Point(x,y);
}

double Dot(Vector A,Vector B){return A.x*B.x+A.y*B.y;}
double Length(Vector A){return sqrt(Dot(A,A));}
double Angle(Vector A, Vector B){return acos(Dot(A,B)/Length(A)/Length(B));}
double Cross(Vector A,Vector B){return A.x*B.y-A.y*B.x;}
double Area2(Point A,Point B,Point C){return Cross(B-A,C-A);}

Vector Rotate(Vector A,double rad){
    return Vector(A.x*cos(rad)-A.y*sin(rad),A.x*sin(rad)+A.y*cos(rad));
}

Vector Normal(Vector A){
    double L=Length(A);
    return Vector(-A.y/L,A.x/L);
}

Point GetLineIntersection(Point P,Vector v,Point Q,Vector w){
    Vector u=P-Q;
    double t=Cross(w,u)/Cross(v,w);
    return P+v*t;
}

double DistanceToLine(Point P,Point A,Point B){
    Vector v1=B-A,v2=P-A;
    return fabs(Cross(v1,v2))/Length(v1);
}

double DistanceToSegment(Point P,Point A,Point B){
    if(A==B)return Length(P-A);
    Vector v1=B-A,v2=P-A,v3=P-B;
    if(dcmp(Dot(v1,v2))<0)return Length(v2);
    else if(dcmp(Dot(v1,v3))>0)return Length(v3);
    else return fabs(Cross(v1,v2))/Length(v1);
}

Point GetLineProjection(Point P,Point A,Point B){
    Vector v=B-A;
    return A+v*(Dot(v,P-A)/Dot(v,v));
}

bool SegmentProperIntersection(Point a1,Point a2,Point b1,Point b2){
    double c1=Cross(a2-a1,b1-a1),c2=Cross(a2-a1,b2-a1),c3=Cross(b2-b1,a1-b1),c4=Cross(b2-b1,a2-b1);
    return dcmp(c1)*dcmp(c2)<0&&dcmp(c3)*dcmp(c4)<0;
}

bool OnSegment(Point p,Point a1,Point a2){
    return dcmp(Cross(a1-p,a2-p))==0&&dcmp(Dot(a1-p,a2-p))<0;
}

double ConvexPolygonArea(Point* p,int n){
    double area=0;
    for(int i=1;i<n-1;i++)
        area+=Cross(p[i]-p[0],p[i+1]-p[0]);
    return area/2;
}

double PolygonArea(Point* p,int n){
    double area=0;
    for(int i=1;i<n-1;i++)
        area+=Cross(p[i]-p[0],p[i+1]-p[0]);
    return area/2;
}

/*int getLineCircleIntersection(Line L,Circle C,double& t1,double& t2,vector<Point>& so1){
    double a=L.v.x,b=L.P.x-C.c.x,c=L.v.y,d=L.P.y-C.c.y;
    double e = a*a+c*c,f=2*(a*b+c*d),g=b*b+d*d-C.r*C.r;
    double delta=f*f-4*e*g;
    if(dcmp(delta)<0)return 0;
    if(dcmp(delta)==0){
        t1=t2=-f/(2*e);so1.push_back(C.point(t1));
        return 1;
    }
    t1=(-f-sqrt(delta))/(2*e);so1.push_back(C.point(t1));
    t2=(-f+sqrt(delta))/(2*e);so1.push_back(C.point(t2));
    return 2;
}*/

double angle(Vector v){
    return atan2(v.y,v.x);
}

int getCircleCircleIntersection(Circle C1,Circle C2,vector<Point>& so1){
    double d=Length(C1.c-C2.c);
    if(dcmp(d)==0){
        if(dcmp(C1.r-C2.r)==0) return -1;
        return 0;
    }
    if(dcmp(C1.r+C2.r-d)<0) return 0;
    if(dcmp(fabs(C1.r-C2.r)-d)>0) return 0;

    double a=angle(C2.c-C1.c);
    double da=acos((C1.r*C2.r+d*d-C2.r*C2.r)/(2*C1.r*d));
    Point p1=C1.point(a-da),p2=C1.point(a+da);
    so1.push_back(p1);
    if(p1==p2) return 1;
    so1.push_back(p2);
    return 2;
}

int getTangents(Point p,Circle C,Vector* v){
    Vector u=C.c-p;
    double dist=Length(u);
    if(dist<C.r) return 0;
    else if(dcmp(dist-C.r)==0){
        v[0]=Rotate(u,PI/2);
        return 1;
    }else{
        double ang = asin(C.r/dist);
        v[0]=Rotate(u,-ang);
        v[1]=Rotate(u,+ang);
        return 2;
    }
}

int getTangents(Circle A,Circle B,Point* a,Point* b){
    int cnt=0;
    if(A.r<B.r){swap(A,B);swap(a,b);}
    int d2=(A.c.x-B.c.x)*(A.c.x-B.c.x)+(A.c.y-B.c.y)*(A.c.y-B.c.y);
    int rdiff=A.r-B.r;
    int rsum=A.r+B.r;
    if(d2<rdiff*rdiff) return 0;
    double base=atan2(B.c.y-A.c.y,B.c.x-A.c.x);
    if(d2==0&&A.r==B.r) return -1;
    if(d2==rdiff*rdiff){
        a[cnt]=A.point(base);
        b[cnt]=B.point(base);
        cnt++;
        return 1;
    }
    double ang=acos((A.r-B.r)/sqrt(d2));
    a[cnt]=A.point(base+ang);b[cnt]=B.point(base+ang);cnt++;
    a[cnt]=A.point(base-ang);b[cnt]=B.point(base-ang);cnt++;
    if(d2==rsum*rsum){
        a[cnt]=A.point(base);b[cnt]=B.point(PI+base);cnt++;
    }
    else if(d2>rsum*rsum){
        double ang=acos((A.r+B.r)/sqrt(d2));
        a[cnt]=A.point(base+ang);b[cnt]=B.point(PI+base+ang);cnt++;
        a[cnt]=A.point(base-ang);b[cnt]=B.point(PI+base-ang);cnt++;
    }
    return cnt;
}

int ConvexHull(Point* p,int n,Point* ch){
    sort(p,p+n);
    int m=0;
    for(int i=0;i<n;i++){
        while(m>1&&Cross(ch[m-1]-ch[m-2],p[i]-ch[m-2])<=0) m--;
        ch[m++]=p[i];
    }
    int k=m;
    for(int i=n-2;i<=0;i--){
        while(m>k&&Cross(ch[m-1]-ch[m-2],p[i]-ch[m-2])<=0) m--;
        ch[m++]=p[i];
    }
    if(n>1) m--;
    return m;
}