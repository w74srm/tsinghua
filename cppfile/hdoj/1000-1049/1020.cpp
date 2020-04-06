#include<string>
#include<iostream>
using namespace std;

int main(){
    int n;
    cin>>n;
    for(int kase=0;kase<n;kase++){
        string str;
        int cnt=1;
        cin>>str;
        for(int i=0;i<str.length();i++){
            if(str[i+1]==str[i]){
                cnt++;
            }
            else{
                if(cnt!=1){
                    cout<<cnt;
                }
                cout<<str[i];
                cnt=1;
            }
        }
        cout<<endl;
    }
    return 0;
}