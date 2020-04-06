#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;
 
struct point
{
	double x , y;
}p[100005];
 
int a[100005];
 
int cmpx(const point &a , const point &b)
{
	return a.x < b.x;
}
int cmpy(int &a , int &b)
{
	return p[a].y < p[b].y;
}
inline double dis(point &a , point &b)
{
	return sqrt( (a.x-b.x)*(a.x-b.x) + (a.y-b.y)*(a.y-b.y));
}
inline double min(double a , double b)
{
	return a < b ? a : b;
}
double closest(int low , int high)
{
	if(low + 1 == high)
		return dis(p[low] , p[high]);
	if(low + 2 == high)
		return min(dis(p[low] , p[high]) , min( dis(p[low] , p[low+1]) , dis(p[low+1] , p[high]) ));
	int mid = (low + high)>>1;
	double ans = min( closest(low , mid) , closest(mid + 1 , high) );
	int i , j , cnt = 0;
	for(i = low ; i <= high ; ++i)
	{
		if(p[i].x >= p[mid].x - ans && p[i].x <= p[mid].x + ans)
			a[cnt++] = i;
	}
	sort(a , a + cnt , cmpy);
	for(i = 0 ; i < cnt ; ++i)
	{
		for(j = i+1 ; j < cnt ; ++j)
		{
			if(p[a[j]].y - p[a[i]].y >= ans)
				break;
			ans = min(ans , dis(p[a[i]] , p[a[j]]));
		}
	}
	return ans;
}
int main(void)
{
	int i,n;
	while(scanf("%d",&n) != EOF)
	{
		if(!n)
			break;
		for(i = 0 ; i < n ; ++i)
			scanf("%lf %lf",&p[i].x,&p[i].y);
		sort(p , p + n , cmpx);
		printf("%.2lf\n",closest(0 , n - 1)/2);  
	}
	return 0;
}