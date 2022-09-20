#include<stdio.h>
#include<queue>
#include<vector>
using namespace std;
 
struct Customer
{
    int index;
    int dtime;
};
vector<queue<Customer>> lines;
int res[1001];
 
int main()
{
    int N, M, K, Q;
    scanf("%d%d%d%d", &N, &M, &K, &Q);
    for (int i = 0; i < N; i++)
    {
        queue<Customer> line;
        lines.push_back(line);
    }
    for (int i = 0; i <= N; i++)
    {
        res[i] = -1;
    }
    for (int i = 0; i < M; i++)
    {
        int loop = true;
        for (int j = 1; j <= N; j++)
        {
            int time = 0;
            scanf("%d", &time);
            Customer c;
            c.index = i*N + j;
            if (lines[j - 1].empty() == false)
            {
                c.dtime = lines[j - 1].back().dtime + time;
            }
            else
            {
                c.dtime = time;
            }
            lines[j - 1].push(c);
            if (c.dtime - time >= 540)
            {
                res[c.index] = -1;
            }
            else
            {
                res[c.index] = c.dtime;
            }
            if (c.index == K)
            {
                loop = false;
                break;
            }
        }
        if (loop == false)
        {
            break;
        }
    }
    for (int i = 0; i < K - M*N; i++)
    {
        int bestline = 0;
        int besttime = 10000000;
        for (int j = 0; j < N; j++)
        {
            if (lines[j].front().dtime < besttime)
            {
                besttime = lines[j].front().dtime;
                bestline = j;
            }
        }
        int time = 0;
        scanf("%d", &time);
        Customer c;
        c.index = M*N + i + 1;
        c.dtime = lines[bestline].back().dtime + time;
        lines[bestline].pop();
        lines[bestline].push(c);
        if (c.dtime - time >= 540)
        {
            res[c.index] = -1;
        }
        else
        {
            res[c.index] = c.dtime;
        }
    }
    for (int i = 0; i < Q; i++)
    {
        int p = 0;
        scanf("%d", &p);
        if (res[p] == -1)
        {
            printf("Sorry\n");
            continue;
        }
        printf("%02d:%02d\n", 8 + res[p] / 60, res[p] % 60);
    }
    return 0;
}