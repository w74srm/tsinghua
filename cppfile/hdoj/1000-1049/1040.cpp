#include<iostream>
using namespace std;

void sort_array (int a[],int n){
    bool sorted = false;
    int t;
    while(!sorted){
        sorted = true;
        for(int i= 1;i<n;i++){
            if(a[i-1]>a[i]){
            t = a[i-1];
            a[i-1] = a[i];
            a[i] = t;
            sorted = false;
            }
        }
    n--; 
    }
}

int main(){
    int t,n,num[1000];
    cin>>t;
    for(int i = 0;i<t;i++){
        cin>>n;
        for(int j=0;j<n;j++){
            cin>>num[j];
        } 
        sort_array(num,n);
        for(int k=0;k<n;k++){
            if(k==n-1)cout<<num[k];
            else cout<<num[k]<<" ";
        }
        cout<<endl;
    }
    return 0;
}
