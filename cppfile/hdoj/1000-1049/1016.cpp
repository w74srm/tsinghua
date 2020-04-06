#include <iostream>
#include<cstdio>
using namespace std;

 int prime[38]= 
 {
     0, 0, 1, 1, 0, 1, 0, 
     1, 0, 0, 0, 1, 0, 1, 
     0, 0, 0, 1, 0, 1, 0, 
     0, 0, 1, 0, 0, 0, 0, 
     0, 1, 0, 1, 0, 0, 0,
     0, 0, 1,
 };

 void Output(int a[], int n)
 {
    for(int i=0;i<n;i++)
	{
	  if(i==n-1)
      cout<<a[i];
	  else
      cout<<a[i]<<" ";
	}
     cout<<endl ;
 }
 
 bool IsOk(int a[], int lastIndex, int curValue)
 {
     if(lastIndex<0)
         return true ;
 
     if(!((curValue+a[lastIndex]) & 1))
         return false ;
 
     if(!prime[a[lastIndex]+curValue])
         return false ;
 
     for(int i = 0; i <= lastIndex; i++)
        if(a[i] == curValue)
         return false ;
 
     return true ;
 }
 
 void PrimeCircle(int a[], int n, int t)
 {
     if(n & 1)
        return;
 
    if(t==n) 
     {
         if(prime[a[0]+a[n-1]])
             Output(a,n); 
     }
     else
     {
         for(int i=2;i<=n;i++)
         {
             a[t]=i;
             if(IsOk(a,t-1,i))
             PrimeCircle(a,n,t+1);
         }
     }
 }
 
 int main()
 {
     int a[20],n,k=1;
     while(scanf("%d",&n)!=EOF)
	 {   
		 cout<<"Case "<<k<<":"<<endl;
		 k++;
		 a[0]=1;
		 PrimeCircle(a,n,1);
		 printf("\n");
	 }
     return 0 ;
 }