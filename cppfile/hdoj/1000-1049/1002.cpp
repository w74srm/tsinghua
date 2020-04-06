#include<cstdio>
#include<string>
#include<iostream>
using namespace std;

int main(){
    int T;
    scanf("%d",&T);
    for(int kase=1;kase<=T;kase++){
        string x,y,a,b;
        cin>>x>>y;
        a=x,b=y;
        int La=a.length(),Lb=b.length();
        if(La<Lb){
            a.swap(b);
            swap(La,Lb);
        }
        a='0'+a;
        La+=1;
        for(int i=Lb+1;i<=La;i++){
            b='0'+b;
        }
        int c=0;
        for(int i=La-1;i>=0;i--){
            int x=a[i]-'0',y=b[i]-'0';
            int s=x+y+c;
            c=s/10;
            a[i]=s%10+'0';
        }
        if(a[0]=='0'){
            a=a.substr(1,La);
        }
        printf("Case %d:\n",kase);
        cout<<x<<" + "<<y<<" = "<<a<<endl<<endl;
    }
    return 0;
}