#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t, n, a[100], b[100], i, k, j;
    char c[100][100];
    double d[100], min;
    cin >> t;
    for (k = 0; k < t; k++)
    {
        memset(a, 0, sizeof(a));
        memset(b, 0, sizeof(b));
        memset(c, 0, sizeof(c)); //二维字符数组清空方法
        memset(d, 0, sizeof(d));
        cin >> n;
        for (i = 0; i < n; i++)
            cin >> c[i] >> a[i] >> b[i];
        for (i = 0; i < n; i++)
        {
            d[i] = (b[i] - b[i] % 200) / 200;
            if (d[i] > 5)
                d[i] = 5;
            d[i] = a[i] / d[i];
        }
        min = d[0];
        j = 0;
        for (i = 0; i < n; i++)
        {
            if (d[i] < min)
            {
                min = d[i];
                j = i;
            }
            if (d[i] == min)
            {
                if (b[i] > b[j])
                {
                    min = d[i];
                    j = i;
                }
            }
        }
        cout << c[j] << endl;
    }
}