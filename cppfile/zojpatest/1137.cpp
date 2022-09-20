#include <iostream>
#include <bits/stdc++.h>
using namespace std;
struct node
{
    string name;
    int gp, gm, gf, g;
};
//如果成绩不相等则按照降序排列，若相等则按照姓名字典序升序排列
bool cmp(node a, node b)
{
    return a.g != b.g ? a.g > b.g : a.name < b.name;
}
map<string, int> idx;
int main()
{
    int p, m, n, score, cnt = 1;
    cin >> p >> m >> n;
    vector<node> v, ans;
    string s;
    for (int i = 0; i < p; i++)
    {
        cin >> s >> score;
        if (score >= 200)
        {
            v.push_back(node{s, score, -1, -1, 0});
            //根据姓名为v设置下标，同时也方便后面判断
            idx[s] = cnt;
            cnt++;
        }
    }
    for (int i = 0; i < m; i++)
    {
        cin >> s >> score;
        if (idx[s] != 0)
            v[idx[s] - 1].gm = score; //v的下标从0开始
    }
    for (int i = 0; i < n; i++)
    {
        cin >> s >> score;
        if (idx[s] != 0)
        {
            int temp = idx[s] - 1;
            v[temp].gf = v[temp].g = score;
            if (v[temp].gm > v[temp].gf)
                v[temp].g = int(v[temp].gm * 0.4 + v[temp].gf * 0.6 + 0.5);
        }
    }
    for (int i = 0; i < v.size(); i++)
        if (v[i].g >= 60)
            ans.push_back(v[i]);
    sort(ans.begin(), ans.end(), cmp);
    for (int i = 0; i < ans.size(); i++)
        printf("%s %d %d %d %d\n", ans[i].name.c_str(), ans[i].gp, ans[i].gm, ans[i].gf, ans[i].g);
    return 0;
}