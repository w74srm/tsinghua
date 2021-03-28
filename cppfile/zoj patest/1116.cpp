#include <cstdio>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;
const int maxn = 10000 + 10;
int N, K;
vector<int> v;
bool flag[maxn] = {false};
bool isPrime(int x)
{
    if (x < 2)
        return false;
    int sq = sqrt(x);
    for (int i = 2; i <= sq; i++)
    {
        if (x % i == 0)
            return false;
    }
    return true;
}
bool find(int x, int &index)
{
    for (int i = 0; i < N; i++)
    {
        if (v[i] == x)
        {
            index = i;
            return true;
        }
    }
    return false;
}
int main()
{
    scanf("%d", &N);
    int t;
    for (int i = 0; i < N; i++)
    {
        scanf("%d", &t);
        v.push_back(t);
    }
    scanf("%d", &K);
    int index = -1;
    for (int i = 0; i < K; i++)
    {
        scanf("%d", &t);
        if (find(t, index))
        {
            if (!flag[index])
            {
                flag[index] = true;
                if (index == 0)
                {
                    printf("%04d: Mystery Award\n", t);
                }
                else if (index != 0)
                {
                    if (isPrime(index + 1))
                    {
                        printf("%04d: Minion\n", t);
                    }
                    else
                        printf("%04d: Chocolate\n", t);
                }
            }
            else
                printf("%04d: Checked\n", t);
        }
        else
            printf("%04d: Are you kidding?\n", t);
    }
    return 0;
}