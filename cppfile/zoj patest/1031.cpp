#include<iostream>
#include<string>
using namespace std;

int main(){
    string str;
    int n1=0,n2=0,n3=0;
    cin>>str;
    int n = str.length();
    int s = n;
    while(s%3!=0){
        s++;
    }
    n1 = n3 = s/3;
    n2 = n-2*n1+2;
    for(int i = 0;i<n1-1;i++){
        cout<<str[i];
        for(int j=0;j<n2-2;j++){
            cout<<' ';
        }
        cout<<str[n-i-1]<<endl;
    }
    for(int i=0;i<n2;i++){
        cout<<str[n1-1+i];
    }
    return 0;
}