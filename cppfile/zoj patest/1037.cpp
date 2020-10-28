#include <iostream>
#include <algorithm>
using namespace std;

bool cmp(long a, long b)
{
    return a > b ? true : false;
}

const int maxm = 100005, maxn = 100005;
long long coupon[maxm];
long long bonus[maxn];

int main()
{
    int m, n;
    cin >> m;
    for (int i = 0; i < m; i++)
    {
        cin >> coupon[i];
    }
    sort(coupon, coupon + m, cmp);
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> bonus[i];
    }
    sort(bonus, bonus + n, cmp);
    long long result = 0;
    for (int i = 0; i < (m < n ? m : n); i++)
    {
        if (coupon[i] > 0 && bonus[i] > 0)
            result += coupon[i] * bonus[i];
        else
            break;
    }
    for (int j = 0; j < (m < n ? m : n); j++)
    {
        if (coupon[m - j - 1] < 0 && bonus[n - j - 1] < 0)
            result += coupon[m - j - 1] * bonus[n - j - 1];
        else
            break;
    }
    cout << result << endl;
    return 0;
}