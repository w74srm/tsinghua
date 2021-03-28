#include <cstdio>
#include <iostream>
#include <queue>
using namespace std;
const int maxn = 10;

struct node
{
    int data;
    int lchild, rchild;
    node() : data(-1), lchild(-1), rchild(-1) {}
} nodes[maxn];

void levelOrder(int root)
{
    queue<int> Q;
    if (root != -1)
    {
        Q.push(root);
    }
    bool flag = false;
    while (!Q.empty())
    {
        int f = Q.front();
        if (!flag)
        {
            cout << nodes[f].data;
            flag = true;
        }
        else
        {
            cout << " " << nodes[f].data;
        }
        Q.pop();
        if (nodes[f].rchild != -1)
            Q.push(nodes[f].rchild);
        if (nodes[f].lchild != -1)
            Q.push(nodes[f].lchild);
    }
}
bool flag = false;
void inOrder(int root)
{
    if (root == -1)
    {
        return;
    }
    inOrder(nodes[root].rchild);
    if (!flag)
    {
        cout << nodes[root].data;
        flag = true;
    }
    else
    {
        cout << " " << nodes[root].data;
    }
    inOrder(nodes[root].lchild);
}
int main()
{
    int N;
    scanf("%d", &N);
    char lchar, rchar;
    bool hashtable[maxn] = {false};
    for (int i = 0; i < N; i++)
    {
        cin >> lchar >> rchar;
        if (lchar != '-')
        {
            nodes[i].lchild = lchar - '0';
            hashtable[lchar - '0'] = true;
        }
        if (rchar != '-')
        {
            nodes[i].rchild = rchar - '0';
            hashtable[rchar - '0'] = true;
        }
        nodes[i].data = i;
    }
    int root;
    for (int i = 0; i < N; i++)
    {
        if (!hashtable[i])
        {
            root = i;
            break;
        }
    }
    levelOrder(root);
    cout << endl;
    inOrder(root);
    return 0;
}