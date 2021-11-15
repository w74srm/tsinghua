#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;
struct point{
    double x, y;
    point(double x=0, double y=0):x(x), y(y) {}
};
 
point operator - (point A, point B) {
    return point(A.x-B.x, A.y-B.y);
}
 
double Cross(point A, point B) {
    return A.x*B.y - A.y*B.x;
}
 
vector<point> v;
int n;
 
int main() {
    int T;
    point tmp;
    scanf("%d", &T);
    while(T--) {
        scanf("%d", &n);
        v.clear();
        for(int i = 0; i < n; i++) {
            scanf("%lf%lf", &tmp.x, &tmp.y);
            v.push_back(tmp);
        }
        point res;
        res.x = 0, res.y = 0;
        double sum = 0, det;
        for(int i = 1; i < n-1; i++) {
            det = Cross(v[i]-v[0], v[i+1]-v[0]);
            res.x += det*(v[0].x+v[i].x+v[i+1].x);
            res.y += det*(v[0].y+v[i].y+v[i+1].y);
            sum += det;
        }
        res.x = res.x/(sum*3);
        res.y = res.y/(sum*3);
        printf("%.2f %.2f\n", res.x, res.y); // G++， C++ 
    }
    return 0;
}