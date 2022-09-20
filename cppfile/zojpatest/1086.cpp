#include <cstdio>
#include <iostream>
#include <string>
#include <stack>
using namespace std;

struct node
{
    int data;
    node *lchild, *rchild;
    node() : lchild(NULL), rchild(NULL) {}
} * root;

bool flag = false;

void postOrder(node *root)
{
    if (!root)
    {
        return;
    }
    postOrder(root->lchild);
    postOrder(root->rchild);
    if (!flag)
    {
        printf("%d", root->data);
        flag = true;
    }
    else
        printf(" %d", root->data);
}

int main()
{
    int N;
    scanf("%d", &N);
    int i = 0;
    string s;
    int t;
    stack<node *> st;
    bool tag = false;
    node *ROOT;
    while (i < N)
    {
        cin >> s;
        if (s == "Push")
        {
            cin >> t;
            node *newNode = new node;
            newNode->data = t;
            if (!tag)
            {
                if (!root)
                {
                    root = newNode;
                    ROOT = root;
                }
                else
                {
                    root->lchild = newNode;
                    root = root->lchild;
                }
            }
            else
            {
                root->rchild = newNode;
                root = root->rchild;
                tag = false;
            }
            st.push(newNode);
            i++;
        }
        else
        {
            tag = true;
            root = st.top();
            st.pop();
        }
    }
    postOrder(ROOT);
    return 0;
}