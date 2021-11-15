#include <iostream>
#include <vector>
#include <map>
#include <cstdio>
using namespace std;
int main()
{
    int n, k, t1, t2;
    map<int, vector<int>> m;
    cin >> n >> k;
    for (int i = 0; i < n; i++)
    {
        cin >> t1 >> t2;
        m[t1].push_back(t2);
    }
    while (k--)
    {
        int cnt, flag = 0, a[100000] = {0};
        cin >> cnt;
        vector<int> v(cnt);
        for (int i = 0; i < cnt; i++)
        {
            cin >> v[i];
            a[v[i]] = 1;
        }
        for (int i = 0; i < v.size(); i++)
            for (int j = 0; j < m[v[i]].size(); j++)
                if (a[m[v[i]][j]] == 1)
                    flag = 1;
        if (flag == 1)
            cout << "No" << endl;
        else
            cout << "Yes" << endl;
    }
    return 0;
}