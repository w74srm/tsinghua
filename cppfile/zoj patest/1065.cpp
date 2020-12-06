#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;
typedef long long LL;
int main(void)
{
    LL a, b, c, res;
    int t, i;
    scanf("%d", &t);
    for (i = 1; i <= t; i++)
    {
        scanf("%lld %lld %lld", &a, &b, &c);
        res = a + b;
        printf("Case #%d: ", i);
        if (a > 0 && b > 0 && res < 0)
        {
            printf("true\n");
        }
        else if (a < 0 && b < 0 && res >= 0)
        {
            printf("false\n");
        }
        else if (res > c)
            printf("true\n");
        else
            printf("false\n");
    }
    return 0;
}