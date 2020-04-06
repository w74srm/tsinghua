#include<cstdio>
#include<cstring>
int a[10]={1,1,2,6,24,120,720,5040};
int b[10];
int main ()
{
	int n,m,i,k,t;
	while(scanf("%d%d",&n,&m)!=EOF)
	{
		for(i=1;i<=n-8;i++)
			printf("%d ",i);
		for(k=0;i<=n;i++)
				b[k++]=i;
		for(i=n>8?8:n;i>1;i--)
		{
			t=(m-1)/a[i-1];
			for(k=0;k<8&&k<n;k++)
			{
				if(b[k]&&t==0)
				{
					printf("%d ",b[k]);
					b[k]=0;
					break;
				}
				else if(b[k])
					t--;
			}
			m=(m-1)%a[i-1]+1;
		}
		for(k=0;k<8&&k<n;k++)
				if(b[k])
					printf("%d\n",b[k]);
	}
	return 0;
}