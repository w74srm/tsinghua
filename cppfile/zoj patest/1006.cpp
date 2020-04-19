#include<cstdio>
#include<iostream>
#include<cstring>
using namespace std;
struct node{
    char id[18];
  int in;
  int out;
}s[110];
int main(){
  int n,i,j,inh,inm,ins,oh,om,os;
  long signin=0,signout=0;
  int max=0,min=99999999;
  int flag1=-1,flag2=-1;
  scanf("%d",&n);
  for(i=0;i<n;i++)
  {  scanf("%s%d:%d:%d%d:%d:%d",s[i].id,&inh,&inm,&ins,&oh,&om,&os);
      signin=inh*3600+inm*60+ins;
    signout=oh*3600+om*60+os;
    if(signin<min) {min=signin;flag1=i;}
    if(signout>max) {flag2=i;max=signout;}
  } 
  printf("%s %s",s[flag1].id,s[flag2].id);
  
  return 0;
}