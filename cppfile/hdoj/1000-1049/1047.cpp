#include<iostream>
#include<string>
using namespace std;
string clear(string a){
    if(a.empty()) a="0";
    while(a[0]=='0') a.erase(0,1);
    if(a.empty()) a="0";
    return a;
}
string add(string a,string b){
    int i=0,tmp,str=0;
    while(a.length()!=b.length())
        a.length()<b.length() ? a='0'+a:b='0'+b;
    a='0'+a;
    b='0'+b;
    i=a.length();
    while(i--){
        tmp=a[i]-'0'+b[i]-'0'+str;
        str=tmp/10;
        a[i]=char(tmp%10+'0');
    }
    a=clear(a);
    return a;
}
 
int main(){
    string s1,s2;
    int t;
    while(cin>>t){
        while(t--){
            s2="0";
            while(1){
                cin>>s1;
                if(s1=="0") break;
                s2=add(s2,s1);
            }
            if(t!=0)
                cout<<s2<<endl<<endl;
            else
                cout<<s2<<endl;
        }
      break;
    }
    return 0;
}