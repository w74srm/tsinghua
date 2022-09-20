#include<iostream>
#include<vector>
#include<cstring>
#include<cmath>
using namespace std;

const int maxn=10000000+10;
int vis[maxn];

int reverse(int n,int radix){
    vector<int> a;
    int res=0;
    while(n>=radix){
        a.push_back(n%radix);
        n/=radix;
    }
    a.push_back(n);
    for(int i=0;i<a.size();i++){
        int temp=a[i];
        for(int j=0;j<(a.size()-i-1);j++){
            temp*=radix;
        }
        res+=temp;
    }
    return res;
}

void sieve(int n){
    int m=(int)sqrt(n+0.5);
    memset(vis,0,sizeof(vis));
    vis[0]=1;
    vis[1]=1;
    for(int i=2;i<=m;i++) if(!vis[i])
        for(int j=i*i;j<=n;j+=i) vis[j]=1;
}

int main(){
    int N,D,reversedN;
    while(cin>>N&&N>=0){
        cin>>D;
        reversedN=reverse(N,D);
        if(reversedN>N) swap(N,reversedN);
        sieve(N);
        if(vis[N]==0&&vis[reversedN]==0) cout<<"Yes"<<endl;
        else cout<<"No"<<endl;
    }
    return 0;
}