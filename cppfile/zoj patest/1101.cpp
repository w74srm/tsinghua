#include <iostream>
#include <vector>
#include <cstdio>
#include <cstring>
#include <string>
#include <algorithm>
using namespace std;

int main()
{
    int N;
    cin >> N;
    vector<int> v;
    int temp;
    while (N--)
    {
        cin >> temp;
        v.push_back(temp);
    }
    vector<int> min, max;
    int Min = 1000000001, Max = 0;
    for (int i = 0; i < v.size(); i++)
    {
        if (Min > v[v.size() - 1 - i])
        {
            Min = v[v.size() - 1 - i];
        }
        min.push_back(Min);
        if (Max < v[i])
        {
            Max = v[i];
        }
        max.push_back(Max);
    }
    reverse(min.begin(), min.end());
    vector<int> vv;
    for (int i = 0; i < v.size(); i++)
    {
        if (min[i] == max[i])
        {
            vv.push_back(v[i]);
        }
    }

    cout << vv.size() << endl;
    sort(vv.begin(), vv.end());
    if (!vv.size())
        cout << endl;
    else
        for (int i = 0; i < vv.size(); i++)
        {
            cout << vv[i];
            if (i != vv.size() - 1)
                cout << " ";
            else
                cout << endl;
        }

    return 0;
}