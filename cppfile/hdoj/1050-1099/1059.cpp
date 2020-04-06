#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
const int maxn=200005;
int a[7],dp[maxn];
 
int main(){
    int cnt=0;
    while(cin>>a[1]>>a[2]>>a[3]>>a[4]>>a[5]>>a[6]){
        memset(dp,0,sizeof(dp));
        cnt++;
        int sum=0;
        for(int i=1;i<=6;i++)
            sum+=a[i]*i;
        if(sum==0)
            break;
        if(sum%2==1){
            printf("Collection #%d:\nCan't be divided.\n",cnt);
            continue;
        }
        sum/=2;
        for(int i=1;i<=6;i++)
            for(int j=1;j<=a[i];j++)
                for(int k=sum;k>=i;k--)
                    dp[k]=max(dp[k],dp[k-i]+i);
        if(dp[sum]==sum)
            printf("Collection #%d:\nCan be divided.\n",cnt);
        else
            printf("Collection #%d:\nCan't be divided.\n",cnt);
    }
    return 0;
}