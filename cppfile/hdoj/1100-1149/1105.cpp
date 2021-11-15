#pragma warning(disable : 4996)
#include <cstdio>
#include <algorithm>
#include <string>
#include <cstring>
#include <stack>
#include <cmath>
#include <queue>
#include <list>
#include <cstdlib>
#include <vector>
#include <set>
#include <map>
#include <sstream>
#include <iostream>
#include <stack>
using namespace std;

const int IS = (1 << 28);
map<int, int> mp;
map<int, int>::iterator it;
map<int, bool> mp_win, mp_lose;
char mm[15][15];
int han, lie, start; //每7位代表坐标。前21位表示狼，22-28为羊位置，29位如果为1代表羊走，否则狼走
int dir[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
bool judge;
void y_win(int s);
void y_lose(int s);
void l_win(int s);
void l_lose(int s);

bool cmp(int x, int y)
{
    return x > y;
}

void translation(int *p, int &h, int &l, int s)
{
    int i;
    for (i = 0; i < 4; i++)
    {
        p[i] = (s & 0x7f);
        s >>= 7;
    }
    h = p[3] / lie;
    l = p[3] % lie;
}

bool is_yes(int *p, int x, int y)
{
    int cy = x * lie + y;
    if (p[0] == cy || p[1] == cy || p[2] == cy || mm[x][y] == 'X' || p[3] == cy)
        return false;
    return true;
}

void y_win(int s)
{
    if (judge)
        return;
    int h, l, x, y, i, p[4], pp[4], k, cy, j, xx, yy, cnt = 0;
    translation(p, h, l, s);
    for (i = 0; i < 3; i++)
    {
        xx = p[i] / lie;
        yy = p[i] % lie;
        for (j = 0; j < 4; j++)
        {
            if (judge)
                return;
            x = xx + dir[j][0];
            y = yy + dir[j][1];
            if (x >= 0 && x < han && y >= 0 && y < lie && is_yes(p, x, y))
            {
                cnt++;
                for (k = 0; k < 3; k++)
                    pp[k] = p[k];
                pp[i] = x * lie + y;
                cy = h * lie + l;
                sort(pp, pp + 3, cmp);
                cy = ((((((cy << 7) | pp[2]) << 7) | pp[1]) << 7) | pp[0]);
                if (mp_win.find(cy) == mp_win.end())
                {
                    mp[cy]--;
                    if (mp[cy] == 0) //狼必败
                    {
                        mp_lose[cy] = true;
                        if (cy == start)
                        {
                            judge = true;
                            return;
                        }
                        l_lose(cy);
                    }
                }
            }
        }
    }
    if (judge)
        return;
    if (cnt == 0)
    {
        cy = (s ^ IS);
        if (mp_win.find(cy) == mp_win.end())
        {
            mp[cy]--;
            if (mp[cy] == 0) //狼必败
            {
                mp_lose[cy] = true;
                if (cy == start)
                {
                    judge = true;
                    return;
                }
                l_lose(cy);
            }
        }
    }
}

void y_lose(int s)
{
    if (judge)
        return;
    int h, l, x, y, i, p[4], pp[4], k, cy, j, xx, yy, cnt = 0;
    translation(p, h, l, s);
    for (i = 0; i < 3; i++)
    {
        xx = p[i] / lie;
        yy = p[i] % lie;
        for (j = 0; j < 4; j++)
        {
            if (judge)
                return;
            x = xx + dir[j][0];
            y = yy + dir[j][1];
            if (x >= 0 && x < han && y >= 0 && y < lie && is_yes(p, x, y))
            {
                cnt++;
                for (k = 0; k < 3; k++)
                    pp[k] = p[k];
                pp[i] = x * lie + y;
                cy = h * lie + l;
                sort(pp, pp + 3, cmp);
                cy = ((((((cy << 7) | pp[2]) << 7) | pp[1]) << 7) | pp[0]);
                if (mp_win.find(cy) == mp_win.end()) //狼必胜
                {
                    mp_win[cy] = true;
                    mp[cy] = 100;
                    if (cy == start)
                    {
                        judge = true;
                        return;
                    }
                    l_win(cy);
                }
            }
        }
    }
    if (judge)
        return;
    if (cnt == 0)
    {
        cy = (s ^ IS);
        if (mp_win.find(cy) == mp_win.end()) //狼必胜
        {
            mp_win[cy] = true;
            mp[cy] = 100;
            if (cy == start)
            {
                judge = true;
                return;
            }
            l_win(cy);
        }
    }
}

void l_win(int s)
{
    if (judge)
        return;
    int h, l, x, y, i, p[4], cy;
    translation(p, h, l, s);
    for (i = 0; i < 4; i++)
    {
        if (judge)
            return;
        x = h + dir[i][0];
        y = l + dir[i][1];
        if (x >= 0 && x < han && y >= 0 && y < lie && is_yes(p, x, y))
        {
            cy = x * lie + y;
            cy = (((((((cy << 7) | p[2]) << 7) | p[1]) << 7) | p[0]) | IS);
            if (mp_win.find(cy) == mp_win.end())
            {
                mp[cy]--;
                if (mp[cy] == 0) //羊必败
                {
                    mp_lose[cy] = true;
                    y_lose(cy);
                    if (judge)
                        return;
                }
            }
        }
    }
}

void l_lose(int s)
{
    if (judge)
        return;
    int h, l, x, y, i, p[4], cy;
    translation(p, h, l, s);
    for (i = 0; i < 4; i++)
    {
        if (judge)
            return;
        x = h + dir[i][0];
        y = l + dir[i][1];
        if (x >= 0 && x < han && y >= 0 && y < lie && is_yes(p, x, y))
        {
            cy = x * lie + y;
            cy = (((((((cy << 7) | p[2]) << 7) | p[1]) << 7) | p[0]) | IS);
            if (mp_win.find(cy) == mp_win.end()) //羊必胜
            {
                mp_win[cy] = true;
                mp[cy] = 100;
                y_win(cy);
                if (judge)
                    return;
            }
        }
    }
}

bool bfs(int s)
{
    queue<int> mq;
    int p[4], pp[4], h, l, cnt, now, i, j, x, y, cy, xx, yy, k;
    mq.push(s);

    while (!mq.empty())
    {
        now = mq.front();
        mq.pop();
        it = mp.find(now);
        if (it != mp.end() && it->second >= 0)
            continue;
        translation(p, h, l, now);
        if (now & IS) //羊走
        {
            if (h == 0 || h == han - 1 || l == 0 || l == lie - 1) //羊必胜
            {
                if (mp_win.find(now) == mp_win.end())
                {
                    mp_win[now] = true;
                    mp[now] = 100;
                    y_win(now);
                    if (judge)
                    {
                        if (mp_win.find(start) != mp_win.end())
                            return false;
                        else
                            return true;
                    }
                }
            }
            else
            {
                cnt = 0;
                for (i = 0; i < 4; i++)
                {
                    x = h + dir[i][0];
                    y = l + dir[i][1];
                    if (is_yes(p, x, y))
                    {
                        cnt++;
                        cy = x * lie + y;
                        cy = ((((((cy << 7) | p[2]) << 7) | p[1]) << 7) | p[0]);
                        if (mp.find(cy) == mp.end() || mp[cy] < 0)
                            mq.push(cy);
                    }
                }
                mp[now] = mp[now] + cnt;
                if (mp[now] == 0) //羊必败
                {
                    mp_lose[now] = true;
                    y_lose(now);
                    if (judge)
                    {
                        if (mp_win.find(start) != mp_win.end())
                            return false;
                        else
                            return true;
                    }
                }
            }
        }
        else
        {
            cnt = 0;
            for (i = 0; i < 3; i++)
            {
                xx = p[i] / lie;
                yy = p[i] % lie;
                for (j = 0; j < 4; j++)
                {
                    x = xx + dir[j][0];
                    y = yy + dir[j][1];
                    if (is_yes(p, x, y) && x >= 0 && x < han && y >= 0 && y < lie)
                    {
                        cnt++;
                        for (k = 0; k < 3; k++)
                            pp[k] = p[k];
                        pp[i] = x * lie + y;
                        cy = h * lie + l;
                        sort(pp, pp + 3, cmp);
                        cy = (((((((cy << 7) | pp[2]) << 7) | pp[1]) << 7) | pp[0]) | IS);
                        if (mp.find(cy) == mp.end() || mp[cy] < 0)
                            mq.push(cy);
                    }
                }
            }
            if (cnt == 0)
            {
                mp[now] = 1;
                cy = (now ^ IS);
                if (mp.find(cy) == mp.end() || mp[cy] < 0)
                    mq.push(cy);
            }
            else
            {
                mp[now] = mp[now] + cnt;
                if (mp[now] == 0) //狼必败
                {
                    mp_lose[now] = true;
                    if (now == start)
                    {
                        judge = true;
                        return true;
                    }
                    l_lose(now);
                    if (judge)
                    {
                        if (mp_win.find(start) != mp_win.end())
                            return false;
                        else
                            return true;
                    }
                }
            }
        }
        if (judge)
        {
            if (mp_win.find(start) != mp_win.end())
                return false;
            else
                return true;
        }
    }
    if (judge)
    {
        if (mp_win.find(start) != mp_win.end())
            return false;
        else
            return true;
    }
    else
        return true;
}

int main()
{
    int i, j, cy;
    while (~scanf("%d %d", &han, &lie))
    {
        start = 0;
        for (i = 0; i < han; i++)
        {
            scanf("%s", mm[i]);
            for (j = 0; j < lie; j++)
            {
                if (mm[i][j] == 'W')
                {
                    start = (start << 7) + i * lie + j;
                }
                if (mm[i][j] == 'S')
                {
                    cy = i * lie + j;
                    cy <<= 21;
                }
            }
        }
        start = (start | cy);
        judge = false;
        mp.clear();
        mp_lose.clear();
        mp_win.clear();
        if (bfs(start))
            puts("Lucky Mmxl is safe:)");
        else
            puts("Poor Mmxl is in danger:(");
    }
    return 0;
}