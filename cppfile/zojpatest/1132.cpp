#include <bits/stdc++.h>
using namespace std;
int main(void)
{
    int n;
    scanf("%d", &n);
    getchar();
    while (n--)
    {
        string s;
        cin >> s;
        //getchar();
        int len = s.size();
        if (len % 2)
        {
            cout << "No" << endl;
            continue;
        }
        string s1, s2;
        s1 = s.substr(0, len / 2);
        s2 = s.substr(len / 2, len / 2);
        int a = stoi(s1);
        int b = stoi(s2);
        int c = stoi(s);
        int flag = 0;
        if (a && b == 0)
        {
            cout << "No" << endl;
            continue;
        }
        if (c % (a * b) == 0)
            flag = 1;
        if (flag)
            cout << "Yes" << endl;
        else
            cout << "No" << endl;
    }
    return 0;
}