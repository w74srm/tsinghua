#include <iostream>
using namespace std;
int main()
{
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        int a,b,m;
        int num=0;
        while(cin>>a>>b)
        {
            m=0;
            num++;
            if((a+b)==0)
            {
                break;
            }
            for(int x=1;x<a;x++)
            {
                for(int y=(x+1);y<a;y++)
                {
                    if((x*x+y*y+b)%(x*y)==0)
                    {
                        m++;
                    }
                }
            }
            cout<<"Case "<<num<<": "<<m<<endl;
        }
        if((i!=(n-1))&&(n!=1))
        {
                 cout<<endl;
        }
    }
    return 0;
}