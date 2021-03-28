#include <iostream>
#include <vector>
const int N = 205;
using namespace std;
int graph[N][N], visit[N];
int main()
{
    int nv, e, m, k, x, y;
    cin >> nv >> e;
    fill(graph[0], graph[0] + N * N, 0);
    while (e--)
    {
        cin >> x >> y;
        graph[x][y] = graph[y][x] = 1;
    }
    cin >> m;
    while (m--)
    {
        int isClique = 1, isMaximum = 1;
        fill(visit, visit + N, 0);
        cin >> k;
        vector<int> v(k);
        for (int i = 0; i < k; i++)
        {
            cin >> v[i];
            visit[v[i]] = 1;
        }
        for (int i = 0; i < k; i++)
        { //1.先判断是否是连通分量
            for (int j = i + 1; j < k; j++)
            {
                if (isClique == 0)
                    break;
                if (graph[v[i]][v[j]] == 0)
                {
                    isClique = 0;
                    cout << "Not a Clique" << endl;
                    break;
                }
            }
        }
        if (isClique == 0)
            continue;
        for (int i = 1; i <= nv; i++)
        { //2.再判断是否是最大连通分量
            if (!visit[i])
            {
                for (int j = 0; j < k; j++)
                {
                    if (graph[i][v[j]] == 0)
                        break;
                    if (j == k - 1)
                    {
                        isMaximum = 0;
                    }
                }
            }
            if (isMaximum == 0)
            {
                cout << "Not Maximal" << endl;
                break;
            }
        }
        if (isMaximum == 1)
            cout << "Yes" << endl;
    }
    return 0;
}
