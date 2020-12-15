#include <cstdio>
#include <vector>
#include <iostream>
using namespace std;

const int maxn = 100000;
struct node
{
    int address;
    int val;
    int next;
} p[maxn];

vector<node> ans, temp;

int main()
{
    int st, n, k, res = 0;
    cin >> st >> n >> k;
    for (int i = 1; i <= n; i++)
    {
        int address, val, next;
        cin >> address >> val >> next;
        p[address].address = address;
        p[address].val = val;
        p[address].next = next;
    }
    int cnt = 0;
    do
    {
        cnt++;
        temp.push_back(p[st]);
        st = p[st].next;
        if (cnt % k == 0)
        {
            for (int i = k - 1; i >= 0; --i)
                ans.push_back(temp[i]);
            temp.clear();
        }
    } while (st != -1);
    for (int i = 0; i < temp.size(); i++)
        ans.push_back(temp[i]);
    int i;
    for (i = 0; i < ans.size() - 1; i++)
    {
        ans[i].next = ans[i + 1].address;
        printf("%05d %d %05d\n", ans[i].address, ans[i].val, ans[i].next);
    }
    printf("%05d %d -1\n", ans[i].address, ans[i].val);
    return 0;
}