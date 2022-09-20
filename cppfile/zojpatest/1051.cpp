#include <iostream>
#include <stack>
#include <vector>
using namespace std;

int main()
{
    int m, n, k;
    cin >> m >> n >> k;
    stack<int> s;
    int t;
    vector<int> ts;
    for (int i = 0; i < k; i++)
    {
        int num = 1;
        int count = 0;
        ts.clear();
        for (int j = 0; j < n; j++)
        {
            cin >> t;
            ts.push_back(t);
        }
        while (1)
        {
            count++;
            if (count > n)
                break;
            t = ts[count - 1];
            while (num <= t)
            {
                s.push(num++);
            }
            if (s.size() > m)
            {
                cout << "NO" << endl;
                break;
            }
            else
            {
                if (t != s.top())
                {
                    cout << "NO" << endl;
                    break;
                }
                else
                    s.pop();
            }
        }
        if (s.empty())
        {
            cout << "YES" << endl;
        }
        while (!s.empty())
        {
            s.pop();
        }
    }
    return 0;
}