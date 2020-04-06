#include<iostream>
using namespace std;

int main(){
    int a[3];
    for(int i=0;i<3;i++){
        cin>>a[i];
    }
    int flag=-1;
    for(int i=0;i<3;i++){
        if(a[i]<168){
            flag=i;
            break;
        }
    }
    if(flag==-1) cout<<"NO CRASH"<<endl;
    else cout<<"CRASH "<<a[flag]<<endl;
    return 0;
}