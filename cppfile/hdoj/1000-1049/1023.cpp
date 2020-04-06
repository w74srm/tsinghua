#include<cstdio>
#include<cstring>
using namespace std;
int a[110][110];
 
void ktl()
{
	int i,j,len;
	int c,s;
	a[1][0]=1;
	a[1][1]=1;
	a[2][0]=1;
	a[2][1]=2;
	len=1;
	for(i=3;i<101;++i)
	{
		c=0;
		for(j=1;j<=len;++j)
		{
			s=a[i-1][j]*(4*i-2)+c;
			c=s/10;
			a[i][j]=s%10;
		}
		while(c)
		{
			a[i][++len]=c%10;
			c/=10;
		}
		for(j=len;j>0;--j)
		{
			s=a[i][j]+c*10;
			a[i][j]=s/(i+1);
			c=s%(i+1);
		}
		while(!a[i][len])
			len--;
		a[i][0]=len;
	}
}
 
int main()
{
	ktl();
	int n;
	while(scanf("%d",&n)!=EOF)
	{
		for(int i=a[n][0];i>0;--i)
			printf("%d",a[n][i]);
		printf("\n");
	}
	return 0;
} 