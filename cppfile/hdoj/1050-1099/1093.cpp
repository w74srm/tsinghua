#include <stdio.h>
int main()
{
    int n, a, b, s, i;
    scanf("%d", &n);
    while (n--)
    {
        s = 0;
        scanf("%d", &a);
        for (i = 1; i <= a; i++)
        {
            scanf("%d", &b);
            s += b;
        }
        printf("%d\n", s);
    }
    return 0;
}