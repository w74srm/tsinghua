#include <stdio.h>
#include <math.h>
__int64 gcd(__int64 a, __int64 b)
{
    return b == 0 ? a : gcd(b, a % b);
}
int main()
{
    __int64 fz, fm, gd;
    int n, i, size1, size2;
    while (~scanf("%d", &n))
    {
        fz = 0;
        fm = 1;
        for (i = 1; i <= n; ++i)
        {
            fz = fz * i + n * fm;
            fm *= i;
            gd = gcd(fz, fm);
            fz /= gd;
            fm /= gd;
        }
        if (fz % fm == 0)
            printf("%I64d\n", fz / fm);
        else
        {
            size1 = (int)log10(1.0 * (fz / fm));
            size2 = (int)log10(1.0 * fm);
            for (i = 0; i <= size1; ++i)
                printf(" ");
            printf(" %I64d\n", fz % fm);
            printf("%I64d ", fz / fm);
            for (i = 0; i <= size2; ++i)
                printf("-");
            printf("\n");
            for (i = 0; i <= size1; ++i)
                printf(" ");
            printf(" %I64d\n", fm);
        }
    }
    return 0;
}