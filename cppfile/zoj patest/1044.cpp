#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;

int main()
{
    int N, M;
    cin >> N >> M;
    int t;
    vector<int> v;
    v.push_back(0);
    for (int i = 1; i <= N; i++)
    {
        cin >> t;
        v.push_back(v[i - 1] + t);
    }
    int l = 0, h = N;
    map<int, int> ma;
    int mid;
    int min1 = 1000000000;
    int minmin = 1000000001;
    for (int i = 0; i <= N; i++)
    {
        l = i;
        h = N;
        while (l <= h)
        {
            mid = (l + h) >> 1;
            int temp = v[mid] - v[i] - M;
            if (temp < 0)
            {
                l = mid + 1;
            }
            else if (min1 > temp)
            {
                min1 = temp;
                h = mid - 1;
            }
            else
                h = mid - 1;
        }
        minmin = min(min1, minmin);
    } //先二分找出离M最小的差距
    for (int i = 0; i <= N; i++)
    {
        l = i;
        h = N;
        while (l <= h)
        {
            mid = (l + h) >> 1;
            int temp = v[mid] - v[i] - M;
            if (temp < minmin)
            {
                l = mid + 1;
            }
            else if (minmin == temp)
            {
                ma[i + 1] = mid;
                break;
            }
            else
                h = mid - 1;
        }
    } //再二分找出所有这样的对
    for (map<int, int>::iterator it = ma.begin(); it != ma.end(); it++)
    {
        printf("%d-%d\n", it->first, it->second);
    }
    return 0;
}