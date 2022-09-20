#include <bits/stdc++.h>
#include <string>

#define INF 1 << 29

using namespace std;

void pat1125()
{
    int n;
    double sum = 0;
    int data[10005];
    cin >> n;
    for (int i = 0; i < n; ++i)
    {
        cin >> data[i];
    }
    sort(data, data + n);
    sum = data[0];
    for (int i = 1; i < n; ++i)
    {
        sum += data[i];
        sum /= 2.0;
    }
    printf("%d\n", (int)sum);
}

int main()
{
    pat1125();
    return 0;
}
