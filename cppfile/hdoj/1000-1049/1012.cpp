#include<iostream>
using namespace std;
int jiecheng(int n)
{
 if(n==1)
 return 1;
 else
 return n*jiecheng(n-1);
}
int main()
{
 int n=9;
 double res=1.0;
 cout<<"n e"<<endl;
 cout<<"- -----------"<<endl;
 cout<<"0 1"<<endl;
 for(int i=1;i<=n;i++)
 {
  res+=1.0/jiecheng(i);
  cout<<i<<" ";
  if(i<3)
   cout<<res<<endl; 
  else
   printf("%.9f\n",res); 
  
 }
 return 0;
}