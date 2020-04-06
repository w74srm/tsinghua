#include<iostream>
using namespace std;

long long f[1000010];
int main(){
    f[3]=0;
    for(long long x=4;x<=100000;x++)
        f[x]=f[x-1]+((x-1)*(x-2)/2-(x-1)/2)/2;
    int n=0;
    while(cin>>n)
    {
        if(n<3) break;
        cout<<f[n]<<endl;
    }
    return 0;
}