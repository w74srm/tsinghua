#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;

struct mooncake
{
    double amount;
    double price;
};

const int maxN = 1005;
mooncake mooncakes[maxN];

bool cmp(mooncake a, mooncake b)
{
    return (a.price / a.amount) > (b.price / b.amount);
}

int main()
{
    int N;
    double D;
    cin >> N >> D;
    for (int i = 0; i < N; i++)
    {
        cin >> mooncakes[i].amount;
    }
    for (int i = 0; i < N; i++)
    {
        cin >> mooncakes[i].price;
    }
    sort(mooncakes, mooncakes + N, cmp);
    double result = 0;
    int idx = 0;
    while (D != 0 && idx < N)
    {
        if (D >= mooncakes[idx].amount)
        {
            result += mooncakes[idx].price;
            D -= mooncakes[idx].amount;
        }
        else
        {
            result += mooncakes[idx].price * D / mooncakes[idx].amount;
            D = 0;
        }
        idx++;
    }
    printf("%.2f", result);
    return 0;
}