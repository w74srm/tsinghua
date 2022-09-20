#include <cstdio>
#include <algorithm>
#include <map>
#include <vector>
#include <set>
#include <queue>
using namespace std;
int N, M, K, X;
const int maxn = 10000 + 10;
const int INF = 1 << 31 - 1;
int isTransfer[maxn] = {0};
vector<int> G[maxn];
vector<int> v, pre[maxn];
int d[maxn];
bool visited[maxn] = {false};
int line[maxn][maxn] = {0}; //保存相邻站之间的线路所在的地铁线
set<int> si;
vector<int> p, x;
struct Node
{
    int v, dis;
} node;
struct compare
{
    bool operator()(Node n1, Node n2)
    {
        return n1.dis > n2.dis;
    }
};
void Dijkstra(int s)
{
    fill(d, d + maxn, INF);
    fill(visited, visited + maxn, false);
    priority_queue<Node, vector<Node>, compare> Q; //必须堆优化，否则超时
    d[s] = 0;
    node.dis = 0;
    node.v = s;
    Q.push(node);
    int u;
    for (set<int>::iterator it = si.begin(); it != si.end(); it++)
    {
        if (!Q.empty())
        {
            u = Q.top().v;
            visited[u] = true;
            Q.pop();
        }
        for (int i = 0; i < G[u].size(); i++)
        {
            int v = G[u][i];
            if (!visited[v])
            {
                if (d[u] + 1 < d[v])
                {
                    d[v] = d[u] + 1;
                    pre[v].clear();
                    pre[v].push_back(u);
                    node.v = v;
                    node.dis = d[v];
                    Q.push(node);
                }
                else if (d[u] + 1 == d[v])
                {
                    pre[v].push_back(u);
                }
            }
        }
    }
}
// 获取换乘的次数
int getTransf(vector<int> a)
{
    int cnt = 0, preLine = 0;
    for (int i = 1; i < a.size(); i++)
    {
        int tempLine = line[a[i - 1]][a[i]];
        if (preLine != tempLine)
        {
            cnt++;
            preLine = tempLine;
        }
    }
    return cnt;
} //其实就是不断比较当前边与上一个边所在线路是不是一致的，不是就说明要换线了
vector<int> path, OptPath;
int minT = INF, T = 0;
void DFS(int s, int e)
{
    if (s == e)
    {
        path.push_back(s);
        T = getTransf(path);
        if (T < minT)
        {
            minT = T;
            OptPath = path;
        }
        path.pop_back();
        return;
    }
    path.push_back(e);
    for (int i = 0; i < pre[e].size(); i++)
    {
        DFS(s, pre[e][i]);
    }
    path.pop_back();
}
int main()
{
    scanf("%d", &N);
    for (int i = 0; i < N; i++)
    {
        scanf("%d", &M);
        v.clear();
        for (int j = 0; j < M; j++)
        {
            scanf("%d", &X);
            v.push_back(X);
            si.insert(X);
        }
        for (int j = 0; j < v.size() - 1; j++)
        {
            G[v[j]].push_back(v[j + 1]);
            G[v[j + 1]].push_back(v[j]);
            line[v[j + 1]][v[j]] = i + 1;
            line[v[j]][v[j + 1]] = i + 1;
        }
    }
    scanf("%d", &K);
    int s, e;
    pair<int, int> pii;
    for (int i = 0; i < K; i++)
    {
        scanf("%d%d", &s, &e);
        path.clear();
        OptPath.clear();
        minT = INF; //记得同时更新
        T = 0;      //
        p.clear();
        x.clear();
        Dijkstra(s);
        DFS(s, e);
        printf("%d\n", OptPath.size() - 1);
        reverse(OptPath.begin(), OptPath.end());
        int sourceIndex = 0, preLine = line[OptPath[0]][OptPath[1]];
        for (int i = 1; i < OptPath.size(); i++)
        {
            int tempLine = line[OptPath[i - 1]][OptPath[i]];
            if (tempLine != preLine)
            {
                printf("Take Line#%d from %04d to %04d.\n", preLine, OptPath[sourceIndex], OptPath[i - 1]);
                sourceIndex = i - 1;
                preLine = tempLine;
            } //要换线时，更新要输出的下一个起点与下一个待比较的线路
        }
        printf("Take Line#%d from %04d to %04d.\n", preLine, OptPath[sourceIndex], OptPath[OptPath.size() - 1]);
        //注意输出最后一个换乘站与终点的线路
    }
    return 0;
}