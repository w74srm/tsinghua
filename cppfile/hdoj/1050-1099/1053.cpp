#include<iostream>
#include<sstream>
#include<iomanip>
using namespace std;
typedef struct{
    int parient,lchild,rchild,weight,length;
    char value;
}HNode;
HNode HT[10000000];

int main(){
    string str;
    while(1){
    getline(cin,str);
    int size=str.size();
    if(str[0]=='E'&&str[1]=='N'&&str[2]=='D'&&size==3)
        return 0;
    int m=1;bool change=0;

    for(int e=1;e<=2*size;++e){
        HT[e].weight=0;
        HT[e].length=0;
        HT[e].parient=0;
    }
    for(int i=0;i<size;++i){
        change=0;
        for(int j=1;j<m;++j){
            if(HT[j].value==str[i]){
                HT[j].weight++;
                change=1;
                break;
            }
        }
        if(change)
            continue;
        HT[m].value=str[i];
        HT[m++].weight=1;
    }int vary=m-1;
    if(vary==1){
        cout<<8*size<<" "<<size<<" "<<8<<"."<<0<<endl;
        continue;
    }
    int SIZE=2*vary-1;
    int x1=1000000000,x2=1000000000,y1=0,y2=0;
    for(int a=m;a<=SIZE;++a){
        int p,q;int sum1=1000000000,sum2=1000000000;
        for(int b=1;b<a;++b){
            if(HT[b].weight<sum1&&HT[b].parient==0){
                sum1=HT[b].weight;
                p=b;
            }
        }
        HT[p].parient=a;
        for(int f=1;f<a;++f){
            if(HT[f].weight<sum2&&HT[f].parient==0){
                sum2=HT[f].weight;
                q=f;
            }
        }
        HT[a].lchild=p;
        HT[a].rchild=q;
        HT[a].weight=HT[p].weight+HT[q].weight;
    HT[q].parient=a;
    }

    for(int c=SIZE;c>vary;--c){
        HT[HT[c].lchild].length=HT[HT[c].rchild].length=HT[c].length+1;
    }
    int time1=8*size;
    int time2=0;
    for(int d=1;d<=vary;++d){
        time2+=HT[d].length*HT[d].weight;
    }
    double time11=time1,time22=time2;
    double timeb=time11/time22;
    int test=timeb*100;
    if(test%10>4){
        test=test/10+1;
    }
    else test=test/10;

    cout<<time1<<" "<<time2<<" "<<test/10<<"."<<test%10<<endl;

    }return 0;

}