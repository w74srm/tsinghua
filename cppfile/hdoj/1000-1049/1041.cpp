#include<iostream>
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int f[1001][400];
void bigdigit()
{
    f[1][0]=0;
    f[2][0]=1;
    f[3][0]=1;
    for(int i=4;i<=1000;i++)
        for(int j=0,b=0;j<=400;j++)
		{
            f[i][j]=b+f[i-1][j]*2+f[i-2][j]-2*f[i-3][j];
            if(f[i][j]<0) 
			f[i][j]+=10,b= -1;
			else 
			b=f[i][j]/10,f[i][j]%=10;
        }
}
int main()
{
    memset(f,0,sizeof(f));
    int n;
    bigdigit();
    while(cin>>n)
    {
        int i;
        if(n==1)
        cout<<"0"<<endl;
        else
        {
            for( i=399;i>=0;i--)
            if(f[n][i]!=0)
            break;
            for(int j=i;j>=0;j--)
            cout<<f[n][j];
            cout<<endl;
        }
    }
    return 0;
}