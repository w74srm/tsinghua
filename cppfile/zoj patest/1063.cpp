#include <cstdio>
#include <set>
#include <algorithm>
using namespace std;

int main()
{
    int n, t, m;
    scanf("%d", &n);
    set<int> *st = new set<int>[n + 1];
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &m);
        for (int j = 0; j < m; j++)
        {
            scanf("%d", &t);
            st[i].insert(t);
        }
    }
    int k;
    scanf("%d", &k);
    int i1, i2;
    for (int i = 0; i < k; i++)
    {
        scanf("%d%d", &i1, &i2);
        int size1 = st[i1].size();
        int count = 0, total = size1;
        for (set<int>::iterator it = st[i2].begin(); it != st[i2].end(); it++)
        {
            if (st[i1].find(*(it)) != st[i1].end())
            {
                count++;
            }
            else
                total++;
        }
        printf("%.1f%%\n", 100 * (double)count / total);
    }
    return 0;
}