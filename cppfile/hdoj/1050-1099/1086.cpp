#include <stdio.h>
#include <iostream>
#include <string.h>
#include <math.h>
#include <algorithm>
using namespace std;

struct Point
{
    double x, y;
} p[205];

///叉积
double mult(Point a, Point b, Point c)
{
    return (a.x - c.x) * (b.y - c.y) - (b.x - c.x) * (a.y - c.y);
}

///a, b为一条线段两端点c, d为另一条线段的两端点 相交返回true, 不相交返回false
bool isCross(Point a, Point b, Point c, Point d)
{
    if (max(a.x, b.x) < min(c.x, d.x))
        return false;
    if (max(a.y, b.y) < min(c.y, d.y))
        return false;
    if (max(c.x, d.x) < min(a.x, b.x))
        return false;
    if (max(c.y, d.y) < min(a.y, b.y))
        return false;
    if (mult(c, b, a) * mult(b, d, a) < 0)
        return false;
    if (mult(a, d, c) * mult(d, b, c) < 0)
        return false;
    return true;
}
int main()
{
    int n;
    while (scanf("%d", &n) != EOF, n)
    {
        int k = 1;
        for (int i = 1; i <= n; i++)
        {
            scanf("%lf%lf%lf%lf", &p[k].x, &p[k].y, &p[k + 1].x, &p[k + 1].y);
            k += 2;
        }
        int ans = 0;
        for (int i = 1; i <= n; i++)
        {
            for (int j = i + 1; j <= n; j++)
            {
                //printf("%lf %lf %lf %lf\n",p[2*i-1].x,p[2*i].x,p[2*j-1].x,p[2*j].x);
                if (isCross(p[2 * i - 1], p[2 * i], p[2 * j - 1], p[2 * j]))
                    ans++;
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}