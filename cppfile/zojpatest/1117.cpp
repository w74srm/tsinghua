#include <cstdio>
#include <algorithm>
using namespace std;
int a[1000000];
bool cmp1(int a, int b)
{
    return a > b;
}
int main()
{
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &a[i]);
    }
    sort(a + 1, a + n + 1, cmp1); //从大到小排序
    int ans = 0;
    int p = 1;
    while (ans <= n && a[p] > p)
    { //若满足，那么1~p-1对应的数肯定是大于p的，然后如果a[p]>p那么刚好就满足那个爱丁顿数
        ans++;
        p++;
    }
    printf("%d", ans);
    return 0;
}