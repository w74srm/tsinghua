#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

struct node
{
    int data;
    node *l, *r;
    node():l(NULL), r(NULL){}
};

void createCBT(node* &root, int N)
{
    queue<node*> Q;
    if (!root)
    {
        root = new node;
        N--;
        if(!N) return;
        Q.push(root);
    }
    while(!Q.empty())
    {
        node* t = Q.front();
        Q.pop();
        if(!t->l)
        {
            t->l = new node;
            Q.push(t->l);
            N--;
            if(!N) return;
        }
        if(!t->r)
        {
            t->r = new node;
            Q.push(t->r);
            N--;
            if(!N) return;
        }
    }
}

vector<int> v;
int index = 0;

void inorder(node* &root)
{
    if(!root) return;
    inorder(root->l);
    root->data = v[index++];
    inorder(root->r);
}

void levelorder(node* root)
{
    queue<node*> Q;
    if (root)
    {
        cout<<root->data;
        Q.push(root);
    }
    while(!Q.empty())
    {
        node* f = Q.front();
        Q.pop();
        if(f->l)
        {
            cout<<" "<<f->l->data;
            Q.push(f->l);
        }
        if(f->r)
        {
            cout<<" "<<f->r->data;
            Q.push(f->r);
        }
    }
}

int main()
{
    int N;
    cin>>N;
    node* root = NULL;
    int t;
    for(int i=0;i<N;i++)
    {
        cin>>t;
        v.push_back(t);
    }
    createCBT(root, N);
    sort(v.begin(), v.end());
    inorder(root);
    levelorder(root);
    return 0;
}