#include <cstdio>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int N;
double P, r;
const int maxn = 100000;
vector<int> children[maxn];
int maxlevel = -1;

void DFS(int root, int l)
{
    maxlevel = max(l, maxlevel);
    if (!children[root].size())
        return;
    for (int i = 0; i < children[root].size(); i++)
    {
        DFS(children[root][i], l + 1);
    }
}

void DFS(int root, int l, int &count)
{
    if (l == maxlevel)
        count++;
    if (!children[root].size())
        return;
    for (int i = 0; i < children[root].size(); i++)
    {
        DFS(children[root][i], l + 1, count);
    }
}

int main()
{
    scanf("%d%lf%lf", &N, &P, &r);
    int t, root;
    for (int i = 0; i < N; i++)
    {
        scanf("%d", &t);
        if (t == -1)
            root = i;
        else
            children[t].push_back(i);
    }
    DFS(root, 0);
    int count = 0;
    DFS(root, 0, count);
    printf("%.2f %d", P * pow((1.0 + r / 100), maxlevel), count);
    return 0;
}