#include<iostream>
#include<cstdio>
using namespace std;

char a[3]={'W','T','L'};

int main(){
    double max[3]={0,0,0},result,temp;
    int f[3]={0,0,0};
    for(int i=0;i<3;i++)
        for(int j=0;j<3;j++){
            cin>>temp;
            if(temp>max[i]){
                max[i]=temp;
                f[i]=j;
            }
        }
    result=(max[0]*max[1]*max[2]*0.65-1)*2;
    printf("%c %c %c %.2lf\n",a[f[0]],a[f[1]],a[f[2]],result);
    return 0;
}