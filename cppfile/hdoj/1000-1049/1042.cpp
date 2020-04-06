#include<iostream>
#include<cstring>
using namespace std;
 
int main()
{
	int n;
	const int maxn = 35660 + 1;//10000!的阶乘一共有35660位
	while(cin>>n){
		int a[maxn];
		memset(a,0,sizeof(a));
		a[maxn-1] = 1;
		int i,j;
		for(i=2;i<=n;i++){
			int c = 0;
			for(j=maxn-1;j>=0;j--){
				int x = a[j]*i + c;
				a[j] = x % 10;
				c = x / 10;
			}
		}
        for(i=0;i<maxn;i++)
			if(a[i])
				break;
		for(j=i;j<maxn;j++)
			cout << a[j];
		cout << endl;
	}
	return 0;
}