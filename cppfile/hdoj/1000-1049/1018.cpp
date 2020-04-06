/*https://blog.csdn.net/qq_41971768/article/details/89460183*/
#include <cstdio>
#include <cmath>
using namespace std;
const double pi = 3.1415926;
 
int main()
{
	int t, n;
	scanf("%d", &t);
	for(int i=0; i<t; ++i)
	{
		scanf("%d", &n);
		int len = ceil((n*log((double)n)-n+log(2.0*(double)n*pi)/2.0)/log(10.0));
		if(!len)
			len++;
		printf("%d\n", len);
	}
 
	return 0;
}