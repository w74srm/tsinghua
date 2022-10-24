#include<bits/stdc++.h>
using namespace std;


vector<vector<int>> getSkyline(vector<vector<int>>& buildings)
{
    auto cmp = [](const pair<int, int>& a, const pair<int, int>& b) -> bool {return a.second < b.second;};
    priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(cmp)> que(cmp);
    vector<int> boundaries;
    for(int i = 0; i < buildings.size(); i++)
    {
        boundaries.emplace_back(buildings[i][0]);
        boundaries.emplace_back(buildings[i][1]);
    }
    sort(boundaries.begin(), boundaries.end());

    vector<vector<int>> result;
    int n = buildings.size(), idx = 0;
    for(auto& boundary : boundaries)
    {
        while(idx < n && buildings[idx][0] <= boundary)
        {
            que.emplace(buildings[idx][1], buildings[idx][2]);
            idx++;
        }
        while(!que.empty() && que.top().first <= boundary)
        {
            que.pop();
        }
        int maxn = que.empty()? 0: que.top().second;
        if(result.size() == 0 || maxn != result.back()[1]) result.push_back({boundary, maxn});
    }
    return result;
}


int main()
{
    int n;
    cin >> n;
    vector<vector<int> > buildings(n, vector<int>(3, 0));
    for(int i = 0; i < n; i++)
    {
        cin >> buildings[i][0] >> buildings[i][1] >> buildings[i][2];
    }
    vector<vector<int>>result = getSkyline(buildings);
    for(int i = 0; i < result.size(); i++)
    {
        cout << result[i][0] << " " << result[i][1] << endl;
    }
    return 0;
}