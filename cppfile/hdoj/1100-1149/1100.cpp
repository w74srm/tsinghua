#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
int ct[19] = {1, 1, 2, 5, 14, 42, 132, 429, 1430, 4862, 16796, 58786, 208012, 742900, 2674440, 9694845, 35357670, 129644790, 477638700};
void dfs(int m, int n)
{
    if (m == 1 && n == 1)
    {
        printf("X");
        return;
    }
    int a = 0, b = m - 1;
    while (b >= 0 && n > ct[a] * ct[b])
    {
        n -= ct[a] * ct[b];
        a++;
        b--;
    }
    if (a != 0)
    {
        printf("(");
        dfs(a, n % ct[b] == 0 ? n / ct[b] : n / ct[b] + 1);
        printf(")");
    }
    printf("X");
    if (b != 0)
    {
        printf("(");
        dfs(b, n % ct[b] == 0 ? ct[b] : n % ct[b]);
        printf(")");
    }
}
int main()
{
    int n;
    while (scanf("%d", &n), n)
    {
        int m = 1;
        while (n > ct[m])
        {
            n -= ct[m];
            m++;
        }
        dfs(m, n);
        printf("\n");
    }
    return 0;
}