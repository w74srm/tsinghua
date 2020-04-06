#include<cstdio>
#include<algorithm>
using namespace std;
int cmp(int a,int b)
{
    return a>b;
}
int main()
{
    int a[1005],b[1005];
    int n;
    while(scanf("%d",&n),n)
    {
        for(int i=0; i<n; i++)
            scanf("%d",&a[i]);
        for(int i=0; i<n; i++)
            scanf("%d",&b[i]);
        sort(a,a+n,cmp);
        sort(b,b+n,cmp);
        int TFirst=0,QFirst=0;
        int TEnd=n-1,QEnd=n-1;
        int win=0;
        while(n--)
        {
            if(a[TFirst]>b[QFirst])
            {
                TFirst++,QFirst++;
                win++;
            }
            else if(a[TEnd]>b[QEnd])
            {
                TEnd--,QEnd--;
                win++;
            }
            else if(a[TEnd]<b[QFirst])
            {
                win--,TEnd--;
                QFirst++;
            }
        }
        printf("%d\n",win*200);
    }
    return 0;
}