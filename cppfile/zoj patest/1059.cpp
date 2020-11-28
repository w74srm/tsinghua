#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;

int main()
{
    vector<int> prime(100001, 1);
    for (int i = 2; i * i < 100001; i++)
    {
        for (int j = 2; j * i < 100001; j++)
            prime[i * j] = 0;
    }

    int n;
    scanf("%d", &n);
    if (n == 1)
    {
        printf("1=1");
        return 0;
    }

    int i = 2, cnt = 0;
    bool state = 0;
    printf("%d=", n);
    for (int i = 2; n >= 2; i++)
    {
        cnt = 0;
        while (prime[i] == 1 && n % i == 0)
        {
            n /= i;
            cnt++;
        }
        if (cnt == 0)
            continue;

        if (state == 1)
            printf("*");

        state = 1;

        if (cnt == 1)
        {
            printf("%d", i);
        }
        else
        {
            printf("%d^%d", i, cnt);
        }
    }

    return 0;
}