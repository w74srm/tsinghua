#include <iostream>
#include <map>
#include <cstdio>
#include <algorithm>
using namespace std;

map<int, int> mm;
int main()
{
    int n;
    scanf("%d", &n);
    int mark;
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        int d;
        scanf("%d", &d);
        if (d != i)
            mm[d] = i;
    }
    mark = mm[0];
    while (mm.size() != 1)
    {
        if (mark == 0)
        {
            map<int, int>::iterator it = mm.begin();
            it++;
            int e = it->first;
            int r = it->second;
            mm[e] = 0;
            mm[0] = r;
            mark = mm[0];
            ans++;
        }
        mm[0] = mm[mark];
        mm.erase(mark);
        mark = mm[0];
        ans++;
    }
    printf("%d", ans);
}