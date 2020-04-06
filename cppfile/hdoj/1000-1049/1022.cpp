#include<cstdio>
#include<vector>
#include<string>
#include<iostream>
using namespace std;

const int maxn=9+1;

int main(){
    int n;
    char strin[maxn],strout[maxn];
    while(scanf("%d%s%s",&n,strin,strout)==3){
        vector<string> result;
        vector<char> station;
        int in=0,out=0;
        for(in=0;in<n;in++){
            station.push_back(strin[in]);
            result.push_back("in");
            while(!station.empty()&&station.back()==strout[out]){
                station.pop_back();
                result.push_back("out");
                out++;
            }
        }
        if(station.empty()){
            printf("Yes.\n");
            for(int i=0;i<result.size();i++){
                cout<<result[i]<<endl;
            }
        }
        else
        {
            printf("No.\n");
        }
        printf("FINISH\n");
    }
    return 0;
}