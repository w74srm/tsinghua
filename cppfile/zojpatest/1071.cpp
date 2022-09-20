#include <iostream>
#include <map>
#include <cstdio>
#include <algorithm>
#include <cstring>
#define inf -100000000
using namespace std;
map<string, int> mm;
int main()
{
    string s;
    getline(cin, s);
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] >= 'A' && s[i] <= 'Z')
        {
            s[i] = s[i] - 'A' + 'a';
        }
    }
    string tmp = "";
    for (int i = 0; i < s.size(); i++)
    {
        if ((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= '0' && s[i] <= '9'))
        {
            tmp += s[i];
        }
        else
        {
            if (tmp == "")
                continue;
            if (mm.find(tmp) != mm.end())
                mm[tmp]++;
            else
                mm[tmp] = 1;
            tmp = "";
        }
    }
    if (tmp != "")
    {
        if (mm.find(tmp) != mm.end())
            mm[tmp]++;
        else
            mm[tmp] = 1;
    }
    map<string, int>::iterator it;
    int maxx = -5;
    string ans;
    for (it = mm.begin(); it != mm.end(); it++)
    {
        if (it->second > maxx)
        {
            maxx = it->second;
            ans = it->first;
        }
    }
    cout << ans << " " << maxx;
}