#include <cstdio>
#include <set>
#include <vector>
#include <algorithm>
using namespace std;
const int maxn = 100000 + 10;
int couple[maxn];
int main()
{
    int N;
    fill(couple, couple + maxn, -1);
    scanf("%d", &N);
    int a, b;
    for (int i = 0; i < N; i++)
    {
        scanf("%d %d", &a, &b);
        couple[a] = b;
        couple[b] = a;
    }
    int M;
    scanf("%d", &M);
    set<int> single;
    int t;
    vector<int> v;
    for (int i = 0; i < M; i++)
    {
        scanf("%d", &t);
        v.push_back(t);
    }
    for (int i = 0; i < M; i++)
    {
        if (couple[v[i]] == -1)
        {
            single.insert(v[i]);
        }
        else
        {

            bool flag = false;
            for (int j = 0; j < M; j++)
            {
                if (v[j] == couple[v[i]])
                {
                    flag = true;
                    break;
                }
            }
            if (!flag)
            {
                single.insert(v[i]);
            }
        }
    }
    printf("%d\n", single.size());
    for (set<int>::iterator it = single.begin(); it != single.end(); it++)
    {
        if (it == single.begin())
            printf("%05d", *it);
        else
            printf(" %05d", *it);
    }
    return 0;
}