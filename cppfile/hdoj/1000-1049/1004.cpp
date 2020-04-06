#include<cstdio>
#include<iostream>
#include<string>
#include<map>
using namespace std;

const int maxn=1000+5;
string balloon[maxn];
map<string,int> strmap;

int main(){
    int n;
    while(scanf("%d",&n)==1&&n){
        strmap.clear();
        for(int i=0;i<n;i++){
            cin>>balloon[i];
            if(strmap.find(balloon[i])==strmap.end()){
                pair<string,int> temp(balloon[i],1);
                strmap.insert(temp);
            }
            else{
                strmap[balloon[i]]++;
            }
        }
        int max=0;
        string maxstr;
        map<string,int>::iterator iter;
        for(iter=strmap.begin();iter!=strmap.end();iter++){
            if(iter->second>max){
                max=iter->second;
                maxstr=iter->first;
            }
        }
        cout<<maxstr<<endl;
    }
}