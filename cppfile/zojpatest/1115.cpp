#include <cstdio>
#include <algorithm>
#include <queue>
using namespace std;
struct Node
{
    int data;
    int depth;
    Node *l, *r;
    Node(int x) : data(x), l(NULL), r(NULL) {}
} * root;
void insert(Node *&root, int x) //这个地方要用引用
{
    if (root == NULL)
    {
        root = new Node(x);
        return;
    }
    else if (x <= root->data)
    {
        insert(root->l, x);
    }
    else
        insert(root->r, x);
}
int maxdepth = -1;
void dfs(Node *root, int depth)
{
    if (!root)
    {
        maxdepth = max(maxdepth, depth);
        return;
    }
    dfs(root->l, depth + 1);
    dfs(root->r, depth + 1);
}
int sum1 = 0, sum2 = 0;
void levelorder(Node *root)
{
    queue<Node *> Q;
    Q.push(root);
    root->depth = 1;
    if (root->depth == maxdepth)
    {
        sum2++;
    }
    else if (root->depth == maxdepth - 1)
        sum1++;
    while (!Q.empty())
    {
        Node *f = Q.front();
        Q.pop();
        if (f->l)
        {
            Q.push(f->l);
            f->l->depth = f->depth + 1;
            if (f->l->depth == maxdepth - 1)
            {
                sum1++;
            }
            else if (f->l->depth == maxdepth)
            {
                sum2++;
            }
        }
        if (f->r)
        {
            Q.push(f->r);
            f->r->depth = f->depth + 1;
            if (f->r->depth == maxdepth - 1)
            {
                sum1++;
            }
            else if (f->r->depth == maxdepth)
            {
                sum2++;
            }
        }
    }
}
int main()
{
    int n;
    scanf("%d", &n);
    int x;
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &x);
        insert(root, x);
    }
    dfs(root, 0);
    levelorder(root);
    printf("%d + %d = %d\n", sum2, sum1, sum1 + sum2);
    return 0;
}