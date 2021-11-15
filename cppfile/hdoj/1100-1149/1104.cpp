#include <iostream>
#include <queue>
#include <string.h>
using namespace std;
const int MAX = 1000010;
const int INF = 0x3fffffff;
char sign[4] = {'+', '-', '*', '%'};
int used[MAX];
int n, k, m, km;
struct Node
{
    int N;
    queue<char> sign;
};

int BFS()
{
    queue<Node> q;
    Node a;
    int i;
    n = (n % km) + km;
    a.N = n;
    q.push(a);
    used[a.N] = 1;

    while (!q.empty())
    {
        Node mid;
        mid = q.front();
        q.pop();

        if (mid.N % k == (n + 1) % k)
        { //判出口
            int len = mid.sign.size();
            cout << len << endl;
            while (!mid.sign.empty())
            {
                cout << mid.sign.front();
                mid.sign.pop();
            }
            cout << endl;
            return 1;
        }
        for (i = 0; i < 4; i++)
        {
            a = mid;
            if (i == 0)
            {
                a.N = (mid.N + m) % km;
                a.sign.push(sign[i]);
                if (!used[a.N])
                {
                    used[a.N] = 1;
                    q.push(a);
                }
            }
            if (i == 1)
            {
                a.N = ((mid.N - m) % km + km) % km;
                a.sign.push(sign[i]);
                if (!used[a.N])
                {
                    used[a.N] = 1;
                    q.push(a);
                }
            }
            if (i == 2)
            {
                a.N = (mid.N * m) % km;
                a.sign.push(sign[i]);
                if (!used[a.N])
                {
                    used[a.N] = 1;
                    q.push(a);
                }
            }
            if (i == 3)
            {
                a.N = (mid.N % m) % km;
                a.sign.push(sign[i]);
                if (!used[a.N])
                {
                    used[a.N] = 1;
                    q.push(a);
                }
            }
        }
    }
    return 0;
}
int main()
{
    while (cin >> n >> k >> m)
    {
        if (n == 0 && k == 0 && m == 0)
            return 0;
        km = k * m;
        memset(used, 0, sizeof(used));
        if (BFS() == 0)
            cout << '0' << endl;
    }
    return 0;
}