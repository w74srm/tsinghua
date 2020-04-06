#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;

struct stick{
    int len,weight;
    bool vis;
    bool operator<(const stick& rhs)const{
        return len<rhs.len||(len==rhs.len&&weight<rhs.len);
    }
}sticks[5005];

bool cmp(stick a,stick b){
    return a.len<b.len||(a.len==b.len&&a.weight<b.weight);
}

int main(){
    int T;
    scanf("%d",&T);
    for(int kase=1;kase<=T;kase++){
        int n,res=0;
        memset(sticks,0,sizeof(sticks));
        scanf("%d",&n);
        for(int i=0;i<n;i++){
            scanf("%d%d",&sticks[i].len,&sticks[i].weight);
            sticks[i].vis=false;
        }
        sort(sticks,sticks+n,cmp);
        for(int i=0;i<n;i++){
            int temp=sticks[i].weight;
            if(!sticks[i].vis){
                for(int j=i+1;j<n;j++){
                    if(!sticks[j].vis&&sticks[j].weight>=temp){
                        sticks[j].vis=true;
                        temp=sticks[j].weight;
                    }
                }
                res++;
            }
        }
        printf("%d\n",res);
    }
    return 0;
}