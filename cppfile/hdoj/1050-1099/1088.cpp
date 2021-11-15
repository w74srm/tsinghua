#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define inf 0x7ffffff
#define eps 1e-9
#define pi acos(-1.0)
using namespace std;

int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    char s[100];
    int cur = 0;
    while (scanf("%s", s) != EOF)
    {
        int len = strlen(s);
        if (strcmp(s, "<br>") == 0)
        {
            printf("\n");
            cur = 0;
            continue;
        }
        if (strcmp(s, "<hr>") == 0)
        {
            if (cur != 0)
                printf("\n");
            for (int i = 0; i < 80; i++)
                printf("-");
            printf("\n"); //这里少了个回车PE了n次
            cur = 0;
            continue;
        }
        if (cur == 0)
        {
            printf("%s", s);
            cur = len;
            if (len == 80)
                cur = 0;
            continue;
        }
        if (len + 1 + cur <= 80)
        {
            printf(" %s", s);
            cur = cur + len + 1;
            if (cur == 80)
                cur = 0;
            continue;
        }
        if (len + 1 + cur > 80)
        {
            printf("\n%s", s);
            cur = len;
            if (cur == 80)
                cur = 0;
        }
    }
    //  if(cur != 0) printf("\n");
    printf("\n");
    return 0;
}