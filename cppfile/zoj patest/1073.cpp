#include <cstdio>
#include <iostream>
#include <string>
#include <cmath>
using namespace std;

int main()
{
    string s, s1, s2;
    cin >> s;
    int exp = 0;
    s1 = s.substr(1, s.find("E") - 1);
    s1.replace(1, 1, "");
    s2 = s.substr(s.find("E") + 1, s.size() - 1);
    int i;

    for (i = 1; i < s2.size(); i++)
    {
        exp += (s2[s2.size() - 1 - i + 1] - '0') * pow(10, i - 1);
    }
    if (s2[0] == '-')
    {
        exp = -exp;
    }

    if (s[0] == '-')
        cout << '-';
    if (exp < 0)
    {
        exp = -exp;
        for (int i = 0; i < exp; i++)
        {
            cout << 0;
            if (i == 0)
                cout << ".";
        }
        cout << s1;
    }
    else
    {
        if (s1.size() > exp + 1)
        {
            s1.insert(exp + 1, ".");
            cout << s1;
        }
        else
        {
            cout << s1;
            for (int i = 0; i < exp + 1 - s1.size(); i++)
            {
                cout << 0;
            }
        }
    }
    return 0;
}