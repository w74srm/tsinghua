#include <cstdio>
#include <algorithm>
using namespace std;
const int maxn = 1000 + 10;
int K, N;
int a[maxn];
int main()
{
    scanf("%d", &K);
    for (int i = 0; i < K; i++)
    {
        scanf("%d", &N);
        for (int j = 0; j < N; j++)
        {
            scanf("%d", &a[j]);
        }
        bool flag = true;
        for (int j = 0; j < N; j++)
        {
            for (int k = 0; k < N; k++)
            {
                if (k != j)
                {
                    if (a[k] == a[j] || abs(a[k] - a[j]) == abs(k - j))
                    {
                        printf("NO\n");
                        flag = false;
                        break;
                    }
                }
            }
            if (!flag)
                break;
        }
        if (flag)
        {
            printf("YES\n");
        }
    }
    return 0;
}