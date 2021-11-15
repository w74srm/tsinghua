#include <cstdio>
#include <iostream>
#include <string.h>
#include <algorithm>
using namespace std;
const int maxn = 10010;
struct node
{
    int num;
    int time;
    int score;
    int id;
} stu[maxn];
int cnt[10];
bool cmp1(node a, node b)
{
    if (a.num > b.num)
        return true;
    if (a.num == b.num)
    {
        if (a.time < b.time)
            return true;
    }
    return false;
}
bool cmp2(node a, node b)
{
    if (a.id < b.id)
        return true;
    return false;
}
int main()
{
    int n;
    int h, m, s;
    while (scanf("%d", &n) != EOF)
    {
        if (n < 0)
            break;
        memset(cnt, 0, sizeof(cnt));
        for (int i = 0; i < n; i++)
        {
            scanf("%d", &stu[i].num);
            stu[i].id = i;
            cnt[stu[i].num]++;
            scanf("%d:%d:%d", &h, &m, &s);
            stu[i].time = s + m * 60 + h * 3600;
        }
        sort(stu, stu + n, cmp1);
        int k = 0;
        for (int i = 5; i >= 0; i--)
        {
            if (i == 5)
            {
                for (int j = 0; j < cnt[i]; j++)
                {
                    stu[k].score = 100;
                    k++;
                }
            }
            else if (i == 0)
            {
                for (int j = 0; j < cnt[0]; j++)
                {
                    stu[k].score = 50;
                    k++;
                }
            }
            else
            {

                for (int j = 0; j < cnt[i] / 2; j++)
                {
                    if (i == 4)
                        stu[k++].score = 95;
                    if (i == 3)
                        stu[k++].score = 85;
                    if (i == 2)
                        stu[k++].score = 75;
                    if (i == 1)
                        stu[k++].score = 65;
                }
                for (int j = cnt[i] / 2; j < cnt[i]; j++)
                {
                    if (i == 4)
                        stu[k++].score = 90;
                    if (i == 3)
                        stu[k++].score = 80;
                    if (i == 2)
                        stu[k++].score = 70;
                    if (i == 1)
                        stu[k++].score = 60;
                }
            }
        }
        sort(stu, stu + n, cmp2);
        for (int i = 0; i < k; i++)
        {
            cout << stu[i].score << endl;
        }
        cout << endl;
    }

    return 0;
}