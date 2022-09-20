#include<iostream>
#include<cstring>
using namespace std;
 
int a[10005];

int main(){
    int m;
    while(cin>>m&&m){
        memset(a,0,sizeof(a));
        int temp=1,max=-9999999,left=1,right=1,sum=0;
        bool positive=false;
        for(int i=1;i<=m;i++){
            cin>>a[i];
            if(a[i]>=0)positive=true;
            sum+=a[i];
            if(sum>max){
                max=sum;
                right=i;
                left=temp;
            }
            if(sum<0){
                sum=0;
                temp=i+1;
            }
        }
        if(positive){cout<<max<<' '<<a[left]<<' '<<a[right]<<endl;}
        else{cout<<0<<' '<<a[1]<<' '<<a[m];}
    }
    return 0;
}