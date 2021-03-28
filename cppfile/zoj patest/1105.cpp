#include <iostream>
#include <vector>
#include <cstdio>
#include <cstring>
#include <string>
#include <algorithm>
#include <iomanip>
#include <cmath>
using namespace std;

int cmp(int a, int b)
{
    return a > b;
}

int main()
{
    int N;
    cin >> N;
    int t;
    int N1 = N;
    vector<int> v;
    while (N--)
    {
        cin >> t;
        v.push_back(t);
    }
    sort(v.begin(), v.end(), cmp); //非递增
    int i;
    for (i = sqrt(N1); i <= N1; i++)
    {
        if (N1 % i == 0)
            break;
    } //m和n肯定一个小于等于N平方根另一个大于等于N平方根
    int m = max(i, N1 / i), n = N1 / m;
    int **a = new int *[m];
    for (int i = 0; i < m; i++)
    {
        a[i] = new int[n];
    }
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            a[i][j] = 0;
        }
    } //必须初始化为0

    i = 0;
    int x = 0, y = 0;
    while (i < N1)
    {
        while (y < n && !a[x][y])
            a[x][y++] = v[i++];
        y--;
        x++;
        while (x < m && !a[x][y])
            a[x++][y] = v[i++];
        x--;
        y--;
        while (y >= 0 && !a[x][y])
            a[x][y--] = v[i++];
        y++;
        x--;
        while (x >= 0 && !a[x][y])
            a[x--][y] = v[i++];
        x++;
        y++;
    }
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << a[i][j];
            if (j != n - 1)
                cout << " ";
            else
                cout << endl;
        }
    }
    return 0;
}