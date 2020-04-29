#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
 
int main()
{
    int i;
    vector<int> n,n2;
    string c;
    cin>>c;
    for(i=c.size()-1;i>=0;i--){
        int t=c[i]-'0';
        n.push_back(t);
    }
 
    int d=0;
    for(i=0;i<n.size();i++){
        if(n[i]*2+d>=10){
            n2.push_back(n[i]*2-10+d);
            d=1;
        }else{
            n2.push_back(n[i]*2+d);
            d=0;
        }
    }
    if(d==1){
        n2.push_back(1);
    }
 
    if(n.size()!=n2.size()){
        cout<<"No"<<endl;
        for(i=n2.size()-1;i>=0;i--){
            cout<<n2[i];
        }
    }else{
        vector<int> a(n2);
        sort(n.begin(),n.end());
        sort(n2.begin(),n2.end());
        int flag=1;
        for(i=0;i<n.size();i++){
            if(n[i]!=n2[i]){
                cout<<"No"<<endl;
                flag=0;
                break;
            }
        }
        if(flag==1){
            cout<<"Yes"<<endl;
        }
        for(i=a.size()-1;i>=0;i--){
            cout<<a[i];
        }
    }
    return 0;
}