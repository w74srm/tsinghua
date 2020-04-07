#include<bits/stdc++.h>
using namespace std;
const int maxn=200005;
int a[7],dp[maxn],w[maxn];
 
int main(){
    int cnt=0;
    while(cin>>a[1]>>a[2]>>a[3]>>a[4]>>a[5]>>a[6]){
        memset(dp,0,sizeof(dp));
        memset(w,0,sizeof(w));
        cnt++;
        int sum=0;
        for(int i=1;i<=6;i++)
            sum+=a[i]*i;
        if(sum==0)
            break;
        if(sum%2==1){
            printf("Collection #%d:\nCan't be divided.\n\n",cnt);
            continue;
        }
        sum/=2;
        int cnt0=1;
        for(int i=1;i<=6;i++){
            for(int j=1;j<=a[i];j<<=1){
                w[cnt0++]=j*i;
                a[i]-=j;
            }
            if(a[i]>0)
                w[cnt0++]=a[i]*i;
        }
        for(int i=1;i<=cnt0;i++)
        for(int j=sum;j>=w[i];j--)
            dp[j]=max(dp[j-w[i]]+w[i],dp[j]);
        if(dp[sum]==sum)
            printf("Collection #%d:\nCan be divided.\n\n",cnt);
        else
            printf("Collection #%d:\nCan't be divided.\n\n",cnt);
    }
    return 0;
}