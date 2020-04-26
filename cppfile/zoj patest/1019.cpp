#include<vector>
#include<iostream>
using namespace std;

vector<int> res;

bool isPalindromicnum(int n,int radix){
    while(n>=radix){
        res.push_back(n%radix);
        n/=radix;
    }
    res.push_back(n);
    int i=0,j=res.size()-1,mid=res.size()/2-1;
    while(i<=mid){
        if(res[i]!=res[j]) return false;
        i++;
        j--;
    }
    return true;
}

int main(){
    int n,radix;
    cin>>n>>radix;
    if(isPalindromicnum(n,radix))cout<<"Yes"<<endl;
    else cout<<"No"<<endl;
    cout<<res.back();
    res.pop_back();
    while(!res.empty()){
        cout<<' '<<res.back();
        res.pop_back();
    }
    cout<<endl;
    return 0;
}