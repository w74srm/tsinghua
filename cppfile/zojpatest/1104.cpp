#include <iostream>
#include <vector>
#include <cstdio>
#include <cstring>
#include <string>
#include <algorithm>
#include <iomanip>
using namespace std;
int main()
{
    int N;
    cin >> N;
    double t;
    int n = N;
    vector<double> v;
    while (N--)
    {
        cin >> t;
        v.push_back(t);
    }
    double sum = 0;

    for (int i = 0; i < v.size(); i++)
    {
        sum += v[i] * (n - i) * (i + 1);
    }
    printf("%.2f", sum);
    return 0;
}