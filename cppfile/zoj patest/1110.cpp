#include <cstdio>
#include <algorithm>
#include <queue>
using namespace std;
const int maxn = 30;
struct node
{
    int data, lchild, rchild;
    node() : lchild(-1), rchild(-1) {}
} nodes[maxn];
bool notroot[maxn] = {false};
int main()
{
    int N;
    scanf("%d", &N);
    char l[3], r[3];
    for (int i = 0; i < N; i++)
    {
        scanf("\n%s %s", l, r); //注意将之前的换行符吸收掉
        nodes[i].data = i;      //注意下标可能是两位数，不能只用一个字符储存！！！！
        if (l[0] != '-')
        {
            nodes[i].lchild = atoi(l);
            notroot[atoi(l)] = true;
        }
        if (r[0] != '-')
        {
            nodes[i].rchild = atoi(r);
            notroot[atoi(r)] = true;
        }
    }
    int root;
    for (int i = 0; i < N; i++)
    {
        if (!notroot[i])
        {
            root = i;
            break; //找根
        }
    }
    queue<node> Q;
    Q.push(nodes[root]);
    int last = root;
    int count = 1;
    while (!Q.empty())
    {
        node nd = Q.front();
        Q.pop();
        if (nd.lchild != -1)
        {
            Q.push(nodes[nd.lchild]);
            count++;
            last = nd.lchild;
        }
        else
            break;
        if (nd.rchild != -1)
        {
            Q.push(nodes[nd.rchild]);
            count++;
            last = nd.rchild;
        }
        else
            break;
    }
    if (count == N)
        printf("YES %d\n", last);
    else
        printf("NO %d\n", root);
    return 0;
}