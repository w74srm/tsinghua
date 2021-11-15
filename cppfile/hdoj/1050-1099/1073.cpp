#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <cmath>
using namespace std;
const int MAXN = 5050;

char a1[MAXN], a2[MAXN];
char b1[MAXN], b2[MAXN];
char temp[MAXN];
void input(char a[], char b[])
{
    gets(temp);
    while (strcmp(temp, "START") != 0)
        gets(temp);

    while (gets(temp))
    {
        if (strcmp(temp, "END") == 0)
            break;
        if (strlen(temp) != 0)
            strcat(a, temp);
        strcat(a, "\n");
    }
    int t = 0;
    int len = strlen(a);
    for (int i = 0; i < len; i++)
    {
        if (a[i] != ' ' && a[i] != '\t' && a[i] != '\n')
            b[t++] = a[i];
    }
    b[t] = '\0';
}

int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int T;
    scanf("%d", &T);
    while (T--)
    {
        a1[0] = '\0';
        a2[0] = '\0';
        input(a1, b1);
        input(a2, b2);
        if (strcmp(a1, a2) == 0)
            printf("Accepted\n");
        else if (strcmp(b1, b2) == 0)
            printf("Presentation Error\n");
        else
            printf("Wrong Answer\n");
    }
    return 0;
}