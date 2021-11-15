#include <bits/stdc++.h>
using namespace std;

#define e exp(1)
#define pi acos(-1)
#define mod 1000000007
#define inf 0x3f3f3f3f
#define ll long long
#define ull unsigned long long
#define mem(a, b) memset(a, b, sizeof(a))
int gcd(int a, int b)
{
    return b ? gcd(b, a % b) : a;
}

const int maxn = 8e3 + 5;
struct node
{
    int val, cnt;
} num[3];
int c1[maxn], c2[maxn];

int main()
{
    num[0].val = 1, num[1].val = 2, num[2].val = 5;
    while (~scanf("%d%d%d", &num[0].cnt, &num[1].cnt, &num[2].cnt))
    {
        if (num[0].cnt == 0 && num[1].cnt == 0 && num[2].cnt == 0)
            break;

        int mav = num[0].cnt * num[0].val + num[1].cnt * num[1].val + num[2].cnt * num[2].val;
        mem(c1, 0);
        mem(c2, 0);
        for (int i = 0; i <= num[0].cnt; i++)
        {
            c1[i] = 1;
        }
        for (int i = 1; i < 3; i++)
        {
            for (int j = 0; j <= mav; j++)
            {
                for (int k = 0; k + j <= mav && k <= num[i].cnt * num[i].val; k += num[i].val)
                {
                    c2[j + k] += c1[j];
                }
            }
            for (int j = 0; j <= mav; j++)
            {
                c1[j] = c2[j];
                c2[j] = 0;
            }
        }
        int i;
        for (i = 1; i <= mav; i++)
        {
            if (!c1[i])
                break;
        }

        printf("%d\n", i);
    }
    return 0;
}