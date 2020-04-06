#include <iostream>
using namespace std;
int main()
{
    int i,j,n,k,a,b,s,m;
    bool flag;
    char x[11][11];
    while (cin>>i>>j>>n && (i!=0||j!=0))
    {
        s=0;flag=false;
        for (k = 0; k < i; k++)
        {
            cin>>x[k];
        }
        a=0;b=n-1;
        while (a>=0&&b>=0&&a<i&&b<j)
        {
            switch (x[a][b])
            {
            case 'N':x[a][b]=s++;a--;break;
            case 'S':x[a][b]=s++;a++;break;
            case 'E':x[a][b]=s++;b++;break;
            case 'W':x[a][b]=s++;b--;break;
            default:
                s=s-x[a][b];flag=true;m=x[a][b];
                break;
            }
            if(flag) break;
        }
        if (flag)
        {
            cout<<m<<" step(s) before a loop of "<<s<<" step(s)"<<endl;
        }
        else
        {
            cout<<s<<" step(s) to exit"<<endl;
        }
    }
    return 0;
}