#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e4 + 10;
int n, m, k;
vector<int> g[maxn];
int col[maxn];
int main()
{
    cin >> n >> m;
    for (int i = 1; i <= m; i++)
    {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    cin >> k;
    while (k--)
    {
        bool flag = false;
        int cnt = 0;
        set<int> s;
        for (int i = 0; i < n; i++)
            cin >> col[i], s.insert(col[i]);
        cnt = s.size();
        // cout<<cnt<<endl;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < g[i].size(); j++)
            {
                if (col[i] == col[g[i][j]])
                {
                    flag = true;
                    break;
                }
            }
            if (flag)
                break;
        }
        if (flag)
            cout << "No\n";
        else
            printf("%d-coloring\n", cnt);
    }
    system("pause");
    return 0;
}
