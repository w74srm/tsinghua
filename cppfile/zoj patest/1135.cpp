#include <bits/stdc++.h>
using namespace std;
vector<int> arr;

struct node
{
    int key;
    struct node *lchild, *rchild;
};

node *build(node *root, int v)
{
    if (root == NULL)
    {
        root = (node *)malloc(sizeof(node));
        root->key = v;
        root->lchild = root->rchild = NULL;
    }
    else if (abs(v) <= abs(root->key))
    {
        root->lchild = build(root->lchild, v);
    }
    else
    {
        root->rchild = build(root->rchild, v);
    }
    return root;
}

bool judge1(node *root)
{
    if (root == NULL)
        return true;
    if (root->key < 0)
    {
        if (root->lchild != NULL && root->lchild->key < 0)
            return false;
        if (root->rchild != NULL && root->rchild->key < 0)
            return false;
    }
    return judge1(root->lchild) && judge1(root->rchild);
}

int getBlackNum(node *root)
{
    if (root == NULL)
        return 0;
    int l = getBlackNum(root->lchild);
    int r = getBlackNum(root->rchild);
    return root->key > 0 ? max(l, r) + 1 : max(l, r);
}

bool judge2(node *root)
{
    if (root == NULL)
        return true;
    int l = getBlackNum(root->lchild);
    int r = getBlackNum(root->rchild);
    if (l != r)
        return false;
    return judge2(root->lchild) && judge2(root->rchild);
}

int main()
{
    int k, n;
    scanf("%d", &k);
    for (int i = 0; i < k; i++)
    {
        node *root = NULL;
        scanf("%d", &n);
        arr.resize(n);
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &arr[j]);
            root = build(root, arr[j]);
        }

        if (arr[0] < 0 || judge1(root) == false || judge2(root) == false)
            printf("No\n");
        else
            printf("Yes\n");
    }
    return 0;
}
