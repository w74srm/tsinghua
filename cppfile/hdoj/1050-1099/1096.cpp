#include <stdio.h>
int main()
{
    int n, m;
    while (scanf("%d", &n) != EOF)
    {
        while (n--)
        {
            scanf("%d", &m);
            int i, a;
            int sum = 0;
            for (i = 1; i <= m; i++)
            {
                scanf("%d", &a);
                sum += a;
            }
            if (n > 0)
                printf("%d\n\n", sum);
            else
                printf("%d\n", sum);
        }
    }
    return 0;
}
