#include <cstdio>
#include <cmath>
using namespace std;

int main()
{
    int n, maxLen = 0, s;

    scanf("%d", &n);
    int sn = (int)sqrt(1.0 * n);
    for (int i = 2; i <= sn; ++i)
    {
        int len = 0, temp = i, k = i;
        while (n % temp == 0)
        {
            ++len;
            ++k;
            temp *= k;
        }

        if (len > maxLen)
        {
            s = i;
            maxLen = len;
        }
    }

    if (maxLen == 0)
    {
        printf("1\n");
        printf("%d\n", n);
    }
    else
    {
        printf("%d\n", maxLen);
        for (int i = 0; i < maxLen; ++i)
        {
            if (i != 0)
            {
                printf("*");
            }
            printf("%d", s + i);
        }
    }

    return 0;
}