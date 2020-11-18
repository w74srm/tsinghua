#include <iostream>
#include <cstdio>
#include <string>
using namespace std;

const int maxn = 10005;

int main(){
    string s1, s2;
    getline(cin, s1);
    getline(cin, s2);
    for(int i=0;i<s1.length();i++){
        bool flag = true;
        for(int j = 0;j<s2.length();j++){
            if(s1[i]==s2[j]){
                flag = false;
                break;
            }
        }
        if(flag == true){
            cout<<s1[i];
        }
    }
    return 0;
}