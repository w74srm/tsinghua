#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;
struct person
{
    int id, total, rank, acCode;
    vector<int> score;
    bool isShown;
};

int cmp(person a, person b)
{
    if (a.total != b.total)
        return a.total > b.total;
    else if (a.acCode != b.acCode)
        return a.acCode > b.acCode;
    return a.id < b.id;
}

int main()
{
    int n, k, m;
    scanf("%d %d %d", &n, &k, &m);
    vector<person> v(n + 1);
    for (int i = 1; i <= n; i++)
        v[i].score.resize(k + 1, -1);
    vector<int> full(k + 1);
    for (int i = 1; i <= k; i++)
    {
        scanf("%d", &full[i]);
    }
    int id, pid, mark;
    for (int i = 0; i < m; i++)
    {
        scanf("%d %d %d", &id, &pid, &mark);
        v[id].id = id;
        if (mark != -1)
        {
            v[id].isShown = true;
            v[id].score[pid] = max(mark, v[id].score[pid]);
        }
        else if (v[id].score[pid] == -1)
        {
            v[id].score[pid] = -2;
        }
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= k; j++)
        {
            if (v[i].score[j] != -1 && v[i].score[j] != -2)
                v[i].total += v[i].score[j];
            if (v[i].score[j] == full[j])
                v[i].acCode++;
        }
    }
    sort(v.begin() + 1, v.end(), cmp);
    v[1].rank = 1;
    for (int i = 2; i <= n; i++)
    {
        v[i].rank = i;
        if (v[i].total == v[i - 1].total)
            v[i].rank = v[i - 1].rank;
    }
    for (int i = 1; i <= n; i++)
    {
        if (v[i].isShown == true)
        {
            printf("%d %05d %d", v[i].rank, v[i].id, v[i].total);
            for (int j = 1; j <= k; j++)
            {
                if (v[i].score[j] != -1 && v[i].score[j] != -2)
                {
                    printf(" %d", v[i].score[j]);
                }
                else if (v[i].score[j] == -1)
                {
                    printf(" -");
                }
                else
                {
                    printf(" 0");
                }
            }
            printf("\n");
        }
    }
    return 0;
}
