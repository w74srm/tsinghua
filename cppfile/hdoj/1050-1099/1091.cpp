#include <stdio.h>
int main()
{
    int a, b;
    while (1) //或者while(scanf("%d%d",&a&b)==2),并且去掉while循环中的第一行
    {
        scanf("%d%d", &a, &b);
        if (a == 0 && b == 0)
            break;
        printf("%d\n", a + b);
    }
    return 0;
}