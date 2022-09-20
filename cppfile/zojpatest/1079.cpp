#include <cstdio>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int N;
double P, r;
const int maxn = 100000;
vector<int> children[maxn];
long long retailer[maxn];
int level[maxn] = {0};
double total = 0.0;

void DFS(int n, double &total, int l)
{
    if (!children[n].size())
    {
        total += P * retailer[n] * pow((r / 100 + 1.0), l);
        return;
    }
    for (int i = 0; i < children[n].size(); i++)
    {
        int temp = children[n][i];
        DFS(temp, total, l + 1);
    }
}

int main()
{
    scanf("%d%lf%lf", &N, &P, &r);
    int t, ID;
    fill(retailer, retailer + maxn, 0);
    for (int i = 0; i < N; i++)
    {
        scanf("%d", &t);
        if (t)
        {
            for (int j = 0; j < t; j++)
            {
                scanf("%d", &ID);
                children[i].push_back(ID);
            }
        }
        else
        {
            scanf("%lld", &retailer[i]);
        }
    }
    DFS(0, total, 0);
    printf("%.1f", total);
    return 0;
}