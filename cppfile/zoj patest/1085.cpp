#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int N;
    long long p;
    cin >> N >> p;
    vector<long long> v;
    long long t;
    for (int i = 0; i < N; i++)
    {
        cin >> t;
        v.push_back(t);
    }
    sort(v.begin(), v.end());
    int len = 0;
    for (int i = 0; i < N; i++)
    {
        for (int j = len + i; j < N; j++)
        {
            if (v[i] * p < v[j])
                break;
            if (len < j - i + 1)
            {
                len = j - i + 1;
            }
        }
    }
    cout << len;
    return 0;
}