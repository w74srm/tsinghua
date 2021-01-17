#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
const int maxn = 100;
struct node
{
    int data;
    int l, r;
    node() : l(-1), r(-1) {}
} nodes[maxn];
int index = 0;
vector<int> v;
void inorder(int root)
{
    if (root == -1)
        return;
    inorder(nodes[root].l);
    nodes[root].data = v[index++];
    inorder(nodes[root].r);
}
void levelorder(int root)
{
    queue<int> Q;
    if (root != -1)
    {
        Q.push(root);
    }
    bool first = true;
    while (!Q.empty())
    {
        int t = Q.front();
        Q.pop();
        if (first)
        {
            printf("%d", nodes[t].data);
            first = false;
        }
        else
            printf(" %d", nodes[t].data);
        if (nodes[t].l != -1)
            Q.push(nodes[t].l);
        if (nodes[t].r != -1)
            Q.push(nodes[t].r);
    }
}
int main()
{
    int N;
    scanf("%d", &N);
    for (int i = 0; i < N; i++)
    {
        scanf("%d %d", &nodes[i].l, &nodes[i].r);
    }
    int t;
    for (int i = 0; i < N; i++)
    {
        scanf("%d", &t);
        v.push_back(t);
    }
    sort(v.begin(), v.end());
    inorder(0);
    levelorder(0);
    return 0;
}