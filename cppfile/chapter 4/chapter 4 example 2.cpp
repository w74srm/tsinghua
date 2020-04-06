#include"point.h"
#include<cstdio>
#include<algorithm>
using namespace std;

const int maxn=300+10;
Point P[maxn],V[maxn*maxn];

int main(){
    int n,kase=0;
    while(scanf("%d",&n)==1&&n){
        for(int i=0;i<n;i++){scanf("%lf%lf",&P[i].x,&P[i].y);V[i]=P[i];}
        n--;
        int c=n,e=n;
        for(int i=0;i<n;i++)
            for(int j=i+1;j<n;j++)
                if(SegmentProperIntersection(P[i],P[i+1],P[j],P[j+1]))V[c++] = GetLineIntersection(P[i],P[i+1]-P[i],P[j],P[j+1]-P[j]);
        sort(V,V+c);
        c=unique(V,V+c)-V;
        for(int i=0;i<c;i++)
            for(int j=0;j<n;j++)
                if(OnSegment(V[i],P[j],P[j+1])) e++;        
        printf("Case %d: There are %d pieces.\n",++kase,e+2-c);
    }
    return 0;
}