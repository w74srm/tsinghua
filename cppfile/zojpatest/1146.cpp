#include <bits/stdc++.h>
using namespace std;
vector<int> graph[1005]; //有向图
int main()
{
    int N, M, a, b;
    scanf("%d%d", &N, &M);
    int degree[N + 1] = {0}; //入度数组
    while (M--)
    {
        scanf("%d%d", &a, &b);
        graph[a].push_back(b);
        ++degree[b];
    }
    scanf("%d", &M);
    bool space = false; //是否输出空格
    for (int k = 0; k < M; ++k)
    {
        int A[N], temp[N + 1];
        for (int i = 0; i < N; ++i)
            scanf("%d", &A[i]);
        copy(degree, degree + N + 1, temp); //将degree数组复制到temp数组中
        for (int i = 0; i < N; ++i)
            if (temp[A[i]] != 0)
            {                                        //当前入度不为0，不是拓扑序列
                printf("%s%d", space ? " " : "", k); //输出
                space = true;
                break;
            }
            else                          //入度为0
                for (int j : graph[A[i]]) //遍历能到达的结点并将入度减1
                    --temp[j];
    }
    return 0;
}