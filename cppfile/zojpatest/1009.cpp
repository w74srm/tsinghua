#include<cstdio>
using namespace std;

int main(){
	double a[1001]={0.0},b[2001]={0.0},t;  //开两个数组，前一个存第一个多项式，下标为次数，值为系数， 后一个要大一些防止越界，并且直接存储结果。 
	int  n1,n2,m,n,i,j;
	scanf("%d",&n1);
	for(i=0;i<n1;i++){
		scanf("%d %lf",&m,&t);
		a[m]=t;
	}
	scanf("%d",&n2);
	for(i=0;i<n2;i++){
		scanf("%d %lf",&m,&t);
		for(j=0;j<1001;j++){
			if(a[j]!=0.0){
				b[m+j]+=a[j]*t;           //这里就是模拟多项式乘法的关键！！ 
			}
		}
	}
	j=0;
	for(i=0;i<2001;i++){
		if(b[i]!=0.0)
			j++;
	}
	printf("%d",j);
	for(i=2000;i>=0;i--){
		if(b[i]!=0.0)
			printf(" %d %.1lf",i,b[i]);
	}
	return 0;
} 