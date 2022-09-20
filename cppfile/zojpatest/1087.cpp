#include <cstdio>
#include <string>
#include <iostream>
#include <map>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
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
const int maxn = 210;
const int INF = 1000000000;
int N, K;
string startCity;
vector<int> pre[maxn];
bool vis[maxn] = {false};
int d[maxn];
int happiness[maxn];
vector<Node> Adj[maxn];
map<string, int> s2i;
map<int, string> i2s;
vector<int> path, tempPath;
int id = 0;
int StringToInt(string s)
{
    if (s2i.find(s) == s2i.end())
    {
        s2i[s] = ++id;
        i2s[id] = s;
        return id;
    }
    else
        return s2i[s];
}

void Dijkstra(int s)
{
    fill(d, d + maxn, INF);
    d[s] = 0;
    priority_queue<Node, vector<Node>, compare> Q;
    node.dis = 0;
    node.v = s;
    Q.push(node);
    int u;
    for (int i = 0; i < N; i++)
    {
        if (!Q.empty())
        {
            u = Q.top().v;
            vis[u] = true;
            Q.pop();
        }
        for (int i = 0; i < Adj[u].size(); i++)
        {
            int v = Adj[u][i].v;
            int dis = Adj[u][i].dis;
            if (!vis[v])
            {
                if (d[u] + dis < d[v])
                {
                    d[v] = d[u] + dis;
                    pre[v].clear();
                    pre[v].push_back(u);
                    node.v = v;
                    node.dis = d[v];
                    Q.push(node);
                }
                else if (d[u] + dis == d[v])
                {
                    pre[v].push_back(u);
                }
            }
        }
    }
}

int start = 0;
int opthappinesssum = -1;
int optaveragehappiness = INF;
int countRoute = 0;

void DFS(int v)
{
    if (v == start)
    {
        countRoute++;
        tempPath.push_back(v);
        int happinesssum = 0, averagehappiness = 0;
        for (int i = 0; i < tempPath.size(); i++)
        {
            int id = tempPath[i];
            happinesssum += happiness[id];
        }
        averagehappiness = happinesssum / (tempPath.size() - 1);
        if (opthappinesssum < happinesssum)
        {
            opthappinesssum = happinesssum;
            path = tempPath;
            optaveragehappiness = averagehappiness; //这里一定要注意更新一下
        }
        else if (opthappinesssum == happinesssum)
        {
            if (optaveragehappiness < averagehappiness)
            {
                optaveragehappiness = averagehappiness;
                path = tempPath;
            }
        }
        tempPath.pop_back();
        return;
    }
    tempPath.push_back(v);
    for (int i = 0; i < pre[v].size(); i++)
    {
        DFS(pre[v][i]);
    }
    tempPath.pop_back();
}

void PrintPath()
{
    for (int i = path.size() - 1; i >= 0; i--)
    {
        cout << i2s[path[i]];
        if (i > 0)
            cout << "->";
        else
            cout << endl;
    }
}

int main()
{
    cin >> N >> K >> startCity;
    s2i[startCity] = 0;
    i2s[0] = startCity;
    string s;
    for (int i = 0; i < N - 1; i++)
    {
        cin >> s;
        int v = StringToInt(s);
        cin >> happiness[v];
    }
    string s1;
    int cost;
    for (int i = 0; i < K; i++)
    {
        cin >> s >> s1 >> cost;
        int u = StringToInt(s);
        int v = StringToInt(s1);
        node.v = v;
        node.dis = cost;
        Adj[u].push_back(node);
        node.v = u;
        Adj[v].push_back(node);
    }
    Dijkstra(0);
    DFS(s2i["ROM"]);
    cout << countRoute << " " << d[s2i["ROM"]] << " "
         << opthappinesssum << " " << optaveragehappiness
         << endl;
    PrintPath();
}