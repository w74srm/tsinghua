#include<cstdio>
#include<algorithm>
#include<cmath>
#include<set>
#include<map>
using namespace std;

const int MOD = 100000007;
const int maxb=500+10;
int n,m,k,b,r,x[maxb],y[maxb];
set<pair<int,int>>bset;

int mul_mod(int a,int p, int n){
    return a*b%n;
}

int pow_mod(int a,int p,int n){
    if(p==0) return 1;
    int ans=pow_mod(a,p/2,n);
    ans = ans*ans%n;
    if(p%2==1) ans = ans*a%n;
    return ans;
}

void gcd(int a,int b,int& d, int& x, int& y){
    if(!b){d=a;x=1;y=0;}
    else{gcd(b,a%b,d,y,x);y-=x*(a/b);}
}

int inv(int a,int n){
    int d,x,y;
    gcd(a,n,d,x,y);
    return d==1?(x+n)%n:-1;
}

int log_mod(int a,int b,int n){
    int m,v,e = 1,i;
    m=(int)sqrt(n+0.5);
    v=inv(pow_mod(a,m,n),n);
    map<int,int> x;
    x[1]=0;
    for(int i=1;i<m;i++){
        e=mul_mod(e,a,n);
        if(!x.count(e)) x[e]=i;
    }
    for(i=0;i<m;i++){
        if(x.count(b)) return i*m+x[b];
        b=mul_mod(b,v,n);
    }
    return -1;
}

int count(){
    int c=0;for(int i=0;i<b;i++){
        if(x[i]!=m&&!bset.count(make_pair(x[i]+1,y[i]))) c++;
    }
    c+=n;
    for(int i=0;i<b;i++) if(x[i]==1) c--;
    return mul_mod(pow_mod(k,c,1),pow_mod(k-1,(long long)m*n-b-c,1),1);
}

int doit(){
    int  cnt=count();
    if(cnt==r) return m;
    int c=0;
    for(int i=0;i<b;i++)
        if(x[i]==m) c++;
    m++;
    cnt = mul_mod(cnt,pow_mod(k,c,1),1);
    cnt = mul_mod(cnt,pow_mod(k-1,n-c,1),1);
    if(cnt==r) return m;
    return log_mod(pow_mod(k-1,n,1),mul_mod(r,inv(cnt,1),1),1);
}

int main(){
    int T;
    scanf("%d",&T);
    for(int t=1;t<=T;t++){
        scanf("%d%d%d%d",&n,&k,&b,&r);
        bset.clear();
        m=1;
        for(int i=0;i<b;i++){
            scanf("%d%d",&x[i],&y[i]);
            if(x[i]>m) m= x[i];
            bset.insert(make_pair(x[i],y[i]));
        }
        printf("Case %d: %d\n",t,doit());
    }
    return 0;
}