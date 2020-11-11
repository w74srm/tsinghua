#include <iostream>
#include <algorithm>
using namespace std;
const int ROW = 201;
const int COL = 10004;

int map[ROW][COL];
int order[ROW];
int stripe[COL];

int N, M, L;

int main()
{
    cin >> N >> M;
    for (int i = 0; i < M; i++)
        cin >> order[i];
    cin >> L;
    for (int i = 0; i < L; i++)
        cin >> stripe[i];
    int i, j;
    if (order[0] == stripe[0])
        map[0][0] = 1;
    else
        map[0][0] = 0;
    for (j = 1; j < L; j++)
    {
        if (order[0] == stripe[j])
            map[0][j] = map[0][j - 1] + 1;
        else
            map[0][j] = map[0][j - 1];
    }
    for (i = 1; i < M; i++)
        if (order[i] == stripe[0])
            map[i][0] = 1;
        else
            map[i][0] = map[i - 1][0];
    for (i = 1; i < M; i++)
    {
        for (j = 1; j < L; j++)
        {
            map[i][j] = max(map[i - 1][j], map[i][j - 1]);
            if (order[i] == stripe[j])
                map[i][j]++;
        }
    }
    cout<<map[M - 1][L - 1];
    return 0;
}