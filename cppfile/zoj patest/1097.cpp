#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
const int MAXN = 100000;
struct Node
{
    int address, data, next;
    Node() : address(-1), data(100001), next(-1) {}
} node[MAXN];
int hashtable[1000010];
int main()
{
    int N, start;
    fill(hashtable, hashtable + 1000010, 0);
    scanf("%d%d", &start, &N);

    int address;
    for (int i = 0; i < N; i++)
    {
        scanf("%d", &address);
        node[address].address = address;
        scanf("%d %d", &node[address].data, &node[address].next);
    }
    if (start == -1 || node[start].data == 100001)
    {
        printf("-1\n-1");
        return 0;
    }
    int pre = start, p = start;
    vector<Node> v;
    //cout << v.size() - 1 << endl;
    while (p != -1)
    {
        if (!hashtable[abs(node[p].data)])
        {
            hashtable[abs(node[p].data)]++;
            pre = p;
            p = node[p].next;
        }
        else
        {
            v.push_back(node[p]);
            node[pre].next = node[p].next;
            p = node[pre].next;
        }
    }
    if (v.size())
    {
        for (int i = 0; i < v.size() - 1; i++) //由于v.size()返回的是无符号整数，若V为空那么减1不是负数！！！！
        {
            v[i].next = v[i + 1].address;
        }
        v[v.size() - 1].next = -1;
    }

    while (start != -1)
    {
        if (node[start].next != -1)
            printf("%05d %d %05d\n", node[start].address, node[start].data, node[start].next);
        else
            printf("%05d %d %d\n", node[start].address, node[start].data, node[start].next);
        start = node[start].next;
    }
    for (int i = 0; i < v.size(); i++)
    {
        if (v[i].next != -1)
            printf("%05d %d %05d\n", v[i].address, v[i].data, v[i].next);
        else
            printf("%05d %d %d\n", v[i].address, v[i].data, v[i].next);
    }
    return 0;
}