#include<set>
#include<iostream>
#include<sstream>
using namespace std;

int next(int n,int k){
    stringstream ss;
    ss<<(long long)k*k;
    string s=ss.str();
    if(s.length()>n) s=s.substr(0,n);
    int ans;
    stringstream ss2(s);
    ss2>>ans;
    return ans;
}

int main(){
    int T;
    cin>>T;
    while(T--){
        int n,k;
        cin>>n>>k;
        set<int> s;
        int ans=k;
        while(!s.count(k)){
            s.insert(k);
            if(k>ans) ans=k;
            k=next(n,k);
        }
        cout<<ans<<endl;
    }
    return 0;
}