/*#include<cstdio>
#include<iostream>
using namespace std;

const int maxn=1000000+10;
int f[maxn];

int main(){
    f[0]=7;
    f[1]=11;
    for(int i=2;i<maxn;i++){
        f[i]=f[i-1]+f[i-2];
    }
    int n;
    while(scanf("%d",&n)==1){
        if(f[n]%3) cout<<"no"<<endl;
        else cout<<"yes"<<endl;
    }
    return 0;
}*/
//2 6 10 14...ok other no
#include <iostream>
using namespace std;
int main()
{
    int n;
    while(cin>>n)
    {
        if((n-2)%4==0)
        {
            cout<<"yes"<<endl;
        }
        else
        {
            cout<<"no"<<endl;
        }
    }
    return 0;
}