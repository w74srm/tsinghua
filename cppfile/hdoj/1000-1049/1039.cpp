#include<iostream>
#include<cstring>
#include<string>
using namespace std;

char vowel[5]={'a','e','i','o','u'};

int isVowel(char a){
    for(int i=0;i<5;i++){
        if(a==vowel[i]) return i;
    }
    return -1;
}

bool isAcceptable(string str){
    int len=str.length(),flag=0;
    for(int i=0;i<len;i++){
        if(isVowel(str[i])>=0){
            flag=1;
            break;
        }
    }
    if(flag==0) return false;
    for(int i=0;i<=len-3;i++){
        if(isVowel(str[i])>=0&&isVowel(str[i+1])>=0&&isVowel(str[i+2])>=0) return false;
        else if(isVowel(str[i])<0&&isVowel(str[i+1])<0&&isVowel(str[i+2])<0) return false;
    }
    for(int i=0;i<=len-2;i++){
        if(str[i]!='e'&&str[i]!='o'&&str[i]==str[i+1]) return false;
    }
    return true;
}

int main(){
    string strin;
    while(cin>>strin&&strin!="end"){
        if(isAcceptable(strin)) cout<<'<'<<strin<<'>'<< " is acceptable."<<endl;
        else cout<<'<'<<strin<<'>'<< " is not acceptable."<<endl;
    }
    return 0;
}