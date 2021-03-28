#include <bits/stdc++.h>
using namespace std;
const int maxn = 10001;
int a[maxn];
int n, m;
unordered_set<int> S;
unordered_set<int>::iterator it1, it2;
int work(int now)
{
    int mid, l = now + 1, r = n;
    while (l <= r)
    {
        mid = (l + r) / 2;
        if (a[mid] < a[now])
        {
            l = mid + 1;
        }
        else
        {
            r = mid - 1;
        }
    }
    return l;
}
int main()
{
    scanf("%d %d", &m, &n);
    S.clear();
    for (int i = 1; i <= n; ++i)
    {
        scanf("%d", &a[i]);
        S.insert(a[i]);
    }
    while (m--)
    {
        int u, v;
        scanf("%d %d", &u, &v);
        if (S.find(u) == S.end() && S.find(v) == S.end())
        {
            printf("ERROR: %d and %d are not found.\n", u, v);
        }
        else if (S.find(u) == S.end())
        {
            printf("ERROR: %d is not found.\n", u);
        }
        else if (S.find(v) == S.end())
        {
            printf("ERROR: %d is not found.\n", v);
        }
        else
        {
            int now = 1, mins = min(u, v), maxx = max(u, v);
            while (true)
            {
                if (a[now] < mins)
                {
                    now = work(now);
                }
                else if (a[now] > maxx)
                {
                    ++now;
                }
                else
                {
                    break;
                }
            }
            if (a[now] == u)
            {
                printf("%d is an ancestor of %d.\n", u, v);
            }
            else if (a[now] == v)
            {
                printf("%d is an ancestor of %d.\n", v, u);
            }
            else
            {
                printf("LCA of %d and %d is %d.\n", u, v, a[now]);
            }
        }
    }
    return 0;
}