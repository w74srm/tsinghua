#include <iostream>
#include <queue>
using namespace std;

struct node
{
    int x, y, z;
};

int M, N, L, T,
    pixel[61][1287][129],
    X[6] = {-1, 1, 0, 0, 0, 0},
    Y[6] = {0, 0, -1, 1, 0, 0},
    Z[6] = {0, 0, 0, 0, -1, 1};
bool visit[61][1287][129] = {false};

bool check(int &x, int &y, int &z);
int count(const int &x, const int &y, const int &z);

int main()
{
    int total = 0;
    scanf("%d%d%d%d", &M, &N, &L, &T);
    for (int i = 0; i < L; i++)
        for (int j = 0; j < M; j++)
            for (int k = 0; k < N; k++)
                scanf("%d", &pixel[i][j][k]);
    for (int i = 0; i < L; i++)
    {
        for (int j = 0; j < M; j++)
        {
            for (int k = 0; k < N; k++)
            {
                if (pixel[i][j][k] == 1 && visit[i][j][k] == false)
                {
                    total += count(i, j, k);
                }
            }
        }
    }
    printf("%d\n", total);
    return 0;
}

int count(const int &x, const int &y, const int &z)
{
    int n = 0;
    node dot = {x, y, z};
    queue<node> Q;
    Q.push(dot);
    visit[x][y][z] = true;
    while (!Q.empty())
    {
        dot = Q.front();
        Q.pop();
        n++;
        for (int i = 0; i < 6; i++)
        {
            node tmp;
            tmp.x = dot.x + X[i];
            tmp.y = dot.y + Y[i];
            tmp.z = dot.z + Z[i];
            if (check(tmp.x, tmp.y, tmp.z))
            {
                Q.push(tmp);
                visit[tmp.x][tmp.y][tmp.z] = true;
            }
        }
    }
    if (n >= T)
        return n;
    else
        return 0;
}

bool check(int &x, int &y, int &z)
{
    if (x < 0 || x >= L || y < 0 || y >= M || z < 0 || z >= N ||
        pixel[x][y][z] == 0 || visit[x][y][z] == true)
    {
        return false;
    }
    return true;
}