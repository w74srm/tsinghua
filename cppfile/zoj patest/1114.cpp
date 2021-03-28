#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;
const int maxn = 10000 + 10;
struct person
{
    int ID, M_estate, area;
    person() : M_estate(0), area(0) {}
} p[maxn];
int father[maxn];
bool flag[maxn] = {false};
int findfather(int x)
{
    if (x == father[x])
        return x;
    else
    {
        int F = findfather(father[x]);
        father[x] = F;
        return F;
    }
}
struct family
{
    int id, m;
    double as, aa;
    bool operator<(family f)
    {
        if (aa != f.aa)
            return aa > f.aa;
        else
            return id < f.id;
    }
};
int main()
{
    for (int i = 0; i < maxn; i++)
    {
        father[i] = i;
    }
    int N, t, a, b, k, c;
    scanf("%d", &N);
    for (int i = 0; i < N; i++)
    {
        scanf("%d", &t);
        flag[t] = true;
        p[t].ID = t;
        int fp = findfather(t);
        scanf("%d%d", &a, &b);
        if (a != -1)
        {
            flag[a] = true;
            int fa = findfather(a);
            if (fa != fp)
                father[fa] = fp;
        }
        if (b != -1)
        {
            flag[b] = true;
            int fb = findfather(b);
            if (fb != fp)
                father[fb] = fp;
        }
        scanf("%d", &k);
        for (int j = 0; j < k; j++)
        {
            scanf("%d", &c);
            if (c != -1)
            {
                flag[c] = true;
                int fc = findfather(c);
                if (fc != fp)
                    father[fc] = fp;
            }
        }
        scanf("%d%d", &p[t].M_estate, &p[t].area);
    }
    vector<family> v;
    family ff;
    for (int i = 0; i < maxn; i++)
    {
        if (flag[i] && father[i] == i)
        {
            int count = 0;
            int sets = 0;
            int areas = 0;
            int minID = 10000;
            for (int j = 0; j < maxn; j++)
            {
                if (flag[j] && findfather(j) == i)
                {
                    count++;
                    sets += p[j].M_estate;
                    areas += p[j].area;
                    minID = min(minID, j);
                }
            }
            ff.id = minID;
            ff.as = (double)sets / count;
            ff.aa = (double)areas / count;
            ff.m = count;
            v.push_back(ff);
        }
    }
    sort(v.begin(), v.end());
    printf("%d\n", v.size());
    for (int i = 0; i < v.size(); i++)
    {
        printf("%04d %d %.3f %.3f\n", v[i].id, v[i].m, v[i].as, v[i].aa);
    }
    return 0;
}