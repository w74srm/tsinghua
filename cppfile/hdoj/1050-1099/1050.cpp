#include<iostream>
#include<cstring>
using namespace std;
int main()
{
    int kase,k;
    cin>>kase;
    for(k=1;k<=kase;k++)
    {
        int n,i,j,count[1000];
        memset(count,0,sizeof(count));
        cin>>n;
        int a,b,temp;
        for(j=1;j<=n;j++)
        {
            
            cin>>a>>b;
            a=(a-1)/2;
            b=(b-1)/2;
            if(a>b)
            {
                temp=a;
                a=b;
                b=temp;
            }
            for(i=a;i<=b;i++)
                count[i]++;
        }
        int max=count[1];
        for(j=1;j<=200;j++)
            if(max<count[j])
                max=count[j];
            cout<<max*10<<endl;
    }
    return 0;
}