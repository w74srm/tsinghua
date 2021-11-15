#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

struct block
{
    int x;
    int y;
    int z;
};

int cmp(const block a, const block b)
{
    return a.x * a.y > b.x * b.y;
}

void work(int n)
{
    block a[100];
    int h[100];
    int i, j, ans;

    for (i = 0; i < n; i++)
    {
        scanf("%d%d%d", &a[3 * i].x, &a[3 * i].y, &a[3 * i].z);

        a[3 * i + 1].x = a[3 * i].z;
        a[3 * i + 1].y = a[3 * i].y;
        a[3 * i + 1].z = a[3 * i].x;

        a[3 * i + 2].x = a[3 * i].x;
        a[3 * i + 2].y = a[3 * i].z;
        a[3 * i + 2].z = a[3 * i].y;
    }

    n = 3 * n;
    sort(a, a + n, cmp);

    //for(i=0;i<n;i++) printf("%d %d %d\n",a[i].x,a[i].y,a[i].z);

    for (i = 0; i < n; i++)
        h[i] = a[i].z;

    for (i = 1; i < n; i++)
        for (j = 0; j < i; j++)
            if ((a[j].x > a[i].x && a[j].y > a[i].y) || (a[j].x > a[i].y && a[j].y > a[i].x))
                if (h[i] < h[j] + a[i].z)
                    h[i] = h[j] + a[i].z;
    ans = 0;
    for (i = 0; i < n; i++)
        ans = h[i] > ans ? h[i] : ans;

    printf("%d\n", ans);
}

int main()
{
    int T, n;
    T = 0;
    while (scanf("%d", &n), n)
    {
        printf("Case %d: maximum height = ", ++T);
        work(n);
    }
    return 0;
}