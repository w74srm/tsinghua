#include <iostream>
#include <bits/stdc++.h>
using namespace std;
//保存节点的值和下一个节点的地址
struct node
{
    int data, next;

} lis[100001];
vector<int> v[3];
int main()
{
    int start, n, k, a;
    cin >> start >> n >> k;
    for (int i = 0; i < n; i++)
    {
        //节点的地址做list的下标
        cin >> a;
        cin >> lis[a].data >> lis[a].next;
    }
    int p = start;
    while (p != -1)
    {
        int data = lis[p].data;
        if (data < 0)
            v[0].push_back(p);
        else if (data >= 0 && data <= k)
            v[1].push_back(p);
        else
            v[2].push_back(p);
        p = lis[p].next;
    }
    //f标记地址是否为空
    int f = 0;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < v[i].size(); j++)
        {
            if (f == 0)
            {
                printf("%05d %d", v[i][j], lis[v[i][j]].data);
                f = 1;
            }
            else
            {
                printf(" %05d\n%05d %d", v[i][j], v[i][j], lis[v[i][j]].data);
            }
        }
    }
    cout << " -1" << endl;
    return 0;
}