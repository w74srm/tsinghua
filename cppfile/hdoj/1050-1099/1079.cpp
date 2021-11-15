#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
#include <map>
#include <set>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <ctime>
#define fuck(x) cout << #x << " = " << x << endl;
#define ls (t << 1)
#define rs ((t << 1) + 1)
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const int maxn = 100086;
const int inf = 2.1e9;
const ll Inf = 999999999999999999;
const int mod = 1000000007;
const double eps = 1e-6;
const double pi = acos(-1);
int date[2005][12][35];
bool judge(int x)
{
    if (x % 100 == 0 && x % 400 != 0)
    {
        return false;
    }
    else
        return x % 4 == 0;
}
int dd[15] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

bool check1(int y, int m, int d)
{
    m++;
    if (m == 13)
    {
        y++;
        m = 1;
    }
    if (judge(y))
    {
        dd[2]++;
    }
    if (d > dd[m])
    {
        if (judge(y))
        {
            dd[2]--;
        }
        return true;
    }
    if (judge(y))
    {
        dd[2]--;
    }
    return date[y][m][d];
}

bool check2(int y, int m, int d)
{
    if (judge(y))
    {
        dd[2]++;
    }
    d++;
    if (d > dd[m])
    {
        m++;
        if (m == 13)
        {
            y++;
            m = 1;
        }
        d = 1;
    }
    if (judge(y))
    {
        dd[2]--;
    }

    return date[y][m][d];
}

void solve(int y, int m, int d)
{
    bool flag1 = check1(y, m, d);
    bool flag2 = check2(y, m, d);
    if (!flag1 || !flag2)
    {
        date[y][m][d] = true;
    }
    else
        date[y][m][d] = false;
}

int main()
{
    //    ios::sync_with_stdio(false);
    //    freopen("in.txt","r",stdin);

    for (int i = 1888; i <= 2002; i++)
    {
        for (int j = 1; j <= 13; j++)
        {
            for (int k = 1; k <= 32; k++)
            {
                date[i][j][k] = true;
            }
        }
    }

    int y, m, d;
    y = 2001, m = 11, d = 4;
    date[y][m][d] = false;
    while (true)
    {
        if (y == 1900 && m == 1 && d == 1)
        {
            break;
        }
        d--;
        if (d == 0)
        {
            m--;
            if (m == 0)
            {
                y--;
                m = 12;
            }
            d = dd[m];
            if (judge(y) && m == 2)
            {
                d++;
            }
        }
        solve(y, m, d);
    }

    int T;
    scanf("%d", &T);
    while (T--)
    {
        scanf("%d%d%d", &y, &m, &d);
        if (date[y][m][d])
        {
            printf("YES\n");
        }
        else
            printf("NO\n");
    }

    return 0;
}