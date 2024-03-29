#include<bits/stdc++.h>
using namespace std;


int maxProfit(int k, vector<int>& prices)
{
    if(prices.empty())
    {
        return 0;
    }
    int n = prices.size();
    k = min(k, n / 2);
    vector<int> buy(k + 1);
    vector<int> sell(k + 1);
    buy[0] = -prices[0];
    sell[0] = 0;
    for(int i = 1; i <= k; i++)
    {
        buy[i] = sell[i] = INT_MIN/2;
    }
    for(int i = 1; i < prices.size(); i++)
    {
        buy[0] = max(buy[0], sell[0] - prices[i]);
        for(int j = 1; j <= k; j++)
        {
            buy[j] = max(buy[j], sell[j] - prices[i]);
            sell[j] = max(sell[j], buy[j-1] + prices[i]);
        }
    }
    return *max_element(sell.begin(), sell.end());
}


int main()
{
    int n, k;
    cin >> n >> k;
    vector<int> prices;
    for(int i = 0; i < n; i++)
    {
        int temp;
        cin >> temp;
        prices.push_back(temp);
    }
    int ans = maxProfit(k, prices);
    cout << ans << endl;
    return 0;
}