#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, m, k, nv, a, b, num;
    cin >> n >> m;
    vector<int> v[n];
    for (int i = 0; i < m; i++)
    {
        cin >> a >> b;
        //记录结点属于哪条边
        v[a].push_back(i);
        v[b].push_back(i);
    }
    cin >> k;
    for (int i = 0; i < k; i++)
    {
        cin >> nv;
        int f = 0;
        //将hash初始化为0
        vector<int> hash(m, 0);
        for (int t = 0; t < nv; t++)
        {
            cin >> num;
            //v[num].size()是记录num属于几条边
            for (int j = 0; j < v[num].size(); j++)
            {
                //查看结点是否有属于的边
                hash[v[num][j]] = 1;
            }
        }
        for (int i = 0; i < m; i++)
        {
            if (hash[i] == 0)
            {
                cout << "No" << endl;
                f = 1;

                break; //不可少
            }
        }
        if (f == 0)
            cout << "Yes" << endl;
    }
    return 0;
}