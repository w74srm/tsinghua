#include <cstdio>
#include <vector>
#include <queue>
using namespace std;
const int maxn = 35;
int in[maxn], post[maxn];
struct Node
{
    int data;
    int depth;
    Node *l, *r;
    Node() : l(NULL), r(NULL) {}
};
int N, maxdepth = -1;
Node *create(int i1, int i2, int p1, int p2)
{
    if (i1 > i2 || p1 > p2)
        return NULL;
    Node *root = new Node();
    root->data = post[p2];
    int k;
    for (int i = i1; i <= i2; i++)
    {
        if (in[i] == root->data)
        {
            k = i;
            break;
        }
    }
    root->l = create(i1, k - 1, p1, p1 + k - 1 - i1);
    root->r = create(k + 1, i2, p2 - 1 - (i2 - k - 1), p2 - 1);
    return root;
}
vector<int> nodes[maxn];
void BFS(Node *root)
{
    queue<Node *> Q;
    root->depth = 0;
    Q.push(root);
    while (!Q.empty())
    {
        Node *f = Q.front();
        Q.pop();
        maxdepth = max(maxdepth, f->depth);
        nodes[f->depth].push_back(f->data);
        if (f->l)
        {
            f->l->depth = f->depth + 1;
            Q.push(f->l);
        }
        if (f->r)
        {
            f->r->depth = f->depth + 1;
            Q.push(f->r);
        }
    }
}
int main()
{
    scanf("%d", &N);
    for (int i = 0; i < N; i++)
        scanf("%d", &in[i]);
    for (int i = 0; i < N; i++)
        scanf("%d", &post[i]);
    Node *root = NULL;
    bool first = true;
    root = create(0, N - 1, 0, N - 1);
    BFS(root);
    for (int i = 0; i <= maxdepth; i++)
    {
        if (i % 2 == 0)
        {
            for (int j = 0; j < nodes[i].size(); j++)
            {
                if (first)
                {
                    first = false;
                    printf("%d", nodes[i][nodes[i].size() - 1 - j]);
                }
                else
                    printf(" %d", nodes[i][nodes[i].size() - 1 - j]);
            }
        }
        else
        {
            for (int j = 0; j < nodes[i].size(); j++)
            {
                if (first)
                {
                    first = false;
                    printf("%d", nodes[i][j]);
                }
                else
                    printf(" %d", nodes[i][j]);
            }
        }
    }
    return 0;
}