#include<iostream>  
#include<cstring>  
using namespace std;  
  
int main(){  
    int n=0,i;  
    char s[1000];  
    while(cin>>s){  
        if(strcmp(s,"0")==0) break;  
        int len=strlen(s);  
        for(i=0;i<len;i++) n+=s[i]-'0';  
        while(n>9){  
            n%=9;  
        }  
        if(n==0)  
            cout<<"9"<<endl;  
        else{  
            cout<<n<<endl;  
            n=0;  
        }  
    }  
    return 0;  
}