#include <cstdio>
#include <cstring>
using namespace std;
const int maxn = 30;
bool hashtable[maxn] = {false};
struct Node
{
    char data[20];
    int leftchild, rightchild;
    Node() : leftchild(-1), rightchild(-1) {}
} Nodes[maxn], node;
int N;
void inOrder(int root, int depth)
{
    if (root != -1)
    {
        if (!(depth == 0 || Nodes[root].leftchild == -1 && Nodes[root].rightchild == -1)) //零层及叶节点不加括号
            printf("(");
        inOrder(Nodes[root].leftchild, depth + 1);
        printf("%s", Nodes[root].data);
        inOrder(Nodes[root].rightchild, depth + 1);
        if (!(depth == 0 || Nodes[root].leftchild == -1 && Nodes[root].rightchild == -1))
            printf(")");
    }
}
int main()
{
    scanf("%d", &N);
    for (int i = 1; i <= N; i++)
    {
        scanf("%s%d%d", node.data, &node.leftchild, &node.rightchild);
        strcpy(Nodes[i].data, node.data);
        Nodes[i].leftchild = node.leftchild;
        Nodes[i].rightchild = node.rightchild;
        hashtable[node.leftchild] = true;
        hashtable[node.rightchild] = true;
    }
    int root = -1;
    for (int i = 1; i <= N; i++)
    {
        if (hashtable[i] == false)
        {
            root = i;
            break; //找根
        }
    }
    inOrder(root, 0);
    return 0;
}