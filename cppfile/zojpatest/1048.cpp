#include <iostream>
#include <algorithm>
using namespace std;

const int maxn = 100005;
const int maxcoin = 1005;
int coins[maxn];
int cnt[maxcoin];

int main()
{
    int n, m;
    int v1, v2;
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        cin >> coins[i];
        cnt[coins[i]]++;
    }
    sort(coins, coins + n);
    int flag = 0;
    for (int i = 0; i < n; i++)
    {
        if (coins[i] > m / 2)
            break;
        int temp = m - coins[i];
        if (temp == coins[i] && cnt[coins[i]] >= 2)
        {
            v1 = v2 = temp;
            flag = 1;
            break;
        }
        else if (temp != coins[i] && cnt[temp] >= 1)
        {
            v1 = coins[i];
            v2 = temp;
            flag = 1;
            break;
        }
    }
    if (flag == 0)
        cout << "No Solution";
    else
        cout << v1 << ' ' << v2;
    return 0;
}