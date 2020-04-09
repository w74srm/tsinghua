#include<cstdio>
#include<string>
#include<cstring>
#include<iostream>
using namespace std;

int main(){
    int T;
    scanf("%d",&T);
    getchar();
    while(T--){
        string str;
        int b=0;
        getline(cin,str);
        for(int i=0;i<=str.length();i++){
            if(str[i]==' '||i==str.length()){
                for(int j=i-1;j>=b;j--) cout<<str[j];
                if(i!=str.length()){
                    cout<<' ';
                    b=i+1;
                }
            }
        }
        cout<<endl;
    }
    return 0;
}