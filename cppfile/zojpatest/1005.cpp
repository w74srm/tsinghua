#include<iostream>
#include<string>
#include<cstring>
using namespace std;

const string num[10]={"zero","one","two","three","four","five","six","seven","eight","nine"};
int result[3];

int transchar(char n){
    return n-'0';
}

int main(){
    string str;
    while(cin>>str){
        int len=str.size(),res=0;
        for(int i=0;i<str.size();i++){
            res+=transchar(str[i]);
        }
        memset(result,0,3);
        int count=0;
        result[count]=res%10;
        res/=10;
        count++;
        while(res>0){
            result[count]=res%10;
            res/=10;
            count++;
        }
        for(int i=count-1;i>=0;i--){
            cout<<num[result[i]];
            if(i)cout<<' ';
        }
        cout<<endl;
    }
    return 0;
}