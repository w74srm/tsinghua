#include <algorithm>
#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>
#include <map>
#include <queue>
#include <string>
using namespace std;
int N;
double P, R;
class node
{
public:
    vector<int> sons;
};
node tree[100010];
int main()
{
    cin >> N >> P >> R;
    for (int i = 0; i < N; i++)
    {
        int k;
        scanf("%d", &k);
        for (int j = 0; j < k; j++)
        {
            int temp;
            scanf("%d", &temp);
            tree[i].sons.push_back(temp);
        }
    }
    queue<int> qus;
    qus.push(0);
    double price = P;
    int sums = 0;
    ;
    while (!qus.empty())
    {
        queue<int> temp;
        if (qus.front() == 0)
        {
            price = P;
        }
        else
        {
            price = price * (R * 0.01 + 1);
        }
        int judge = 0;
        while (!qus.empty())
        {
            int tno = qus.front();
            qus.pop();
            if (tree[tno].sons.size() == 0)
            {
                judge = 1;
                sums++;
            }
            else
            {
                for (int i = 0; i < tree[tno].sons.size(); i++)
                {
                    temp.push(tree[tno].sons[i]);
                }
            }
        }
        if (judge == 1)
        {
            break;
        }
        qus = temp;
    }
    cout << fixed << setprecision(4) << price << " ";
    cout << sums << '\n';
}
