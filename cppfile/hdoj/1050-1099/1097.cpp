#include<stdio.h>
#include<math.h>
int main()
{
    int a,b;
 
    while(~scanf("%d%d",&a,&b))
    {
        a%=10;
        b%=4;
        if(b==0)
            b=4;
        a=pow(a,b);
        printf("%d\n",a%10);
    }
    return 0;
}