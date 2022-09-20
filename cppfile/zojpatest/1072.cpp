#include <cstdio>
#include <iostream>
#include <vector>

using namespace std;
const int SIZE = 1013;

bool visited[SIZE];
int dis[SIZE];
vector<int> adjlist[SIZE];

int Mindis = 0;
int Sum = 0.0;
int number;
void Reset(const int &n)
{
    for (int i = 1; i <= n; i++)
    {
        visited[i] = false;
        dis[i] = 0x1 << 30;
    }
}

void Dijkstra(const int &root, const int n, int m, const int max)
{
    dis[root] = 0;
    visited[root] = true;
    int curmindis, sum = 0;
    for (int i = 0; i < adjlist[root].size(); i += 2)
    {
        int index = adjlist[root][i];
        dis[index] = adjlist[root][i + 1];
    }
    bool flag = false;
    for (int j = 1; j < n + m; j++)
    {
        int next = 0;
        int mindis = 0x1 << 30;
        for (int i = 1; i <= n + m; i++)
        {
            if (!visited[i] && dis[i] < mindis)
            {
                next = i;
                mindis = dis[i];
            }
        }
        if (next <= n)
        {
            if (!flag)
            {
                flag = true;
                curmindis = dis[next];
            }
            if (dis[next] > max)
                return;
            else
            {
                sum += dis[next];
            }
        }
        visited[next] = true;
        int size = adjlist[next].size();
        for (int i = 0; i < size; i += 2)
        {
            int index = adjlist[next][i];
            int distance = adjlist[next][i + 1];
            if (dis[index] > distance + dis[next])
                dis[index] = distance + dis[next];
        }
    }

    if (Mindis < curmindis || Mindis == curmindis && sum < Sum)
    {
        number = root;
        Mindis = curmindis;
        Sum = sum;
    }
}

int Stoi(const char *p, const int &n)
{
    int res = 0;
    if (*p == 'G')
    {
        res = n;
        p++;
    }
    int tmp = 0;
    while (*p != '\0')
    {
        tmp = 10 * tmp + *p - '0';
        p++;
    }
    return res + tmp;
}

void display(const int &n)
{
    for (int i = 1; i <= n; i++)
    {
        int size = adjlist[i].size();
        for (int j = 0; j < size; j++)
            cout << adjlist[i][j] << ' ';
        cout << endl;
    }
}

int main()
{
    int N, M, K, Ds;
    scanf("%d%d%d%d", &N, &M, &K, &Ds);
    for (int i = 0; i < K; i++)
    {
        char s1[8], s2[8];
        int diss;
        int n1, n2;
        scanf("%s%s%d", s1, s2, &diss);
        n1 = Stoi(s1, N);
        n2 = Stoi(s2, N);
        adjlist[n1].push_back(n2);
        adjlist[n1].push_back(diss);
        adjlist[n2].push_back(n1);
        adjlist[n2].push_back(diss);
    }
    for (int j = N + 1; j <= N + M; j++)
    {
        Reset(N + M);
        Dijkstra(j, N, M, Ds);
    }
    if (!Sum)
        printf("No Solution\n");
    else
        printf("G%d\n%.1f %.1f", number - N, Mindis * 1.0, Sum * 1.0 / N);

    return 0;
}