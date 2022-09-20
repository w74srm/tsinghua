#include <cstdio>
#include <algorithm>
using namespace std;
const int maxn = 10000 + 10;
bool flag[maxn] = {false};
int N, K, B;
int father[maxn];
int findFather(int x)
{
    if (x == father[x])
        return x;
    else
    {
        int F = findFather(father[x]);
        father[x] = F;
        return F;
    }
}
int main()
{
    for (int i = 0; i < maxn; i++)
    {
        father[i] = i;
    }
    scanf("%d", &N);
    int count = 0;
    for (int i = 0; i < N; i++)
    {
        scanf("%d", &K);
        int bf;
        for (int j = 0; j < K; j++)
        {
            scanf("%d", &B);
            if (!flag[B])
            {
                count++;
                flag[B] = true;
            }
            if (j == 0)
            {
                bf = findFather(B);
            }
            else if (findFather(B) != findFather(bf))
            {
                father[findFather(B)] = findFather(bf);
            }
        }
    }
    int trees = 0;
    for (int i = 1; i <= count; i++)
    {
        if (father[i] == i)
        {
            trees++;
        }
    }
    printf("%d %d\n", trees, count);
    int Q;
    scanf("%d", &Q);
    int a, b;
    for (int i = 0; i < Q; i++)
    {
        scanf("%d %d", &a, &b);
        if (findFather(a) == findFather(b))
            printf("Yes\n");
        else
            printf("No\n");
    }
    return 0;
}