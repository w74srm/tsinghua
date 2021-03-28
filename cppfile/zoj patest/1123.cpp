#include <cstdio>
#include <algorithm>
#include <queue>
using namespace std;
struct Node
{
    int data;
    int height;
    Node *l, *r;
    Node() : height(1), l(NULL), r(NULL) {}
};
int getHeight(Node *n)
{
    if (!n)
        return 0;
    return n->height;
}
int getBalanceFactor(Node *n)
{
    return getHeight(n->l) - getHeight(n->r);
}
void updateHeight(Node *n)
{
    n->height = max(getHeight(n->l), getHeight(n->r)) + 1;
}
void L(Node *&n)
{
    Node *temp = n->r;
    n->r = temp->l;
    temp->l = n;
    updateHeight(n);
    updateHeight(temp);
    n = temp;
}
void R(Node *&n)
{
    Node *temp = n->l;
    n->l = temp->r;
    temp->r = n;
    updateHeight(n);
    updateHeight(temp);
    n = temp;
}
void insert(Node *&n, int x) //修改了指针本身要加引用
{
    if (!n)
    {
        n = new Node;
        n->data = x;
        return;
    }
    if (x < n->data)
    {
        insert(n->l, x);
        updateHeight(n);
        if (getBalanceFactor(n) == 2)
        {
            if (getBalanceFactor(n->l) == 1)
            {
                R(n);
            }
            else if (getBalanceFactor(n->l) == -1)
            {
                L(n->l);
                R(n);
            }
        }
    }
    else
    {
        insert(n->r, x);
        updateHeight(n);
        if (getBalanceFactor(n) == -2)
        {
            if (getBalanceFactor(n->r) == -1)
            {
                L(n);
            }
            else if (getBalanceFactor(n->r) == 1)
            {
                R(n->r);
                L(n);
            }
        }
    }
}
int maxindex = -1;
void dfs(Node *n, int index)
{
    if (!n)
        return;
    maxindex = max(maxindex, index);
    dfs(n->l, 2 * index);
    dfs(n->r, 2 * index + 1);
}
void levelOrder(Node *root)
{
    queue<Node *> Q;
    Q.push(root);
    bool first = true;
    while (!Q.empty())
    {
        Node *n = Q.front();
        Q.pop();
        if (first)
        {
            printf("%d", n->data);
            first = false;
        }
        else
            printf(" %d", n->data);
        if (n->l)
            Q.push(n->l);
        if (n->r)
            Q.push(n->r);
    }
}
int main()
{
    int N;
    scanf("%d", &N);
    Node *root = NULL;
    int x;
    for (int i = 0; i < N; i++)
    {
        scanf("%d", &x);
        insert(root, x);
    }
    levelOrder(root);
    printf("\n");
    dfs(root, 1);
    if (maxindex == N)
    {
        printf("YES");
    }
    else
        printf("NO");
    return 0;
}