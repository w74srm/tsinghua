#include <iostream>
#include <cstdio>
#include <string>
#include <string.h>
#include <map>
using namespace std;
map<string, string> m;
map<string, string>::iterator it;
char a[3010], b[3010];
int main()
{
    scanf("%s", a);
    while (1)
    {
        scanf("%s", a);
        if (strcmp(a, "END") == 0)
            break;
        scanf("%s", b);
        m[b] = a;
    }
    scanf("%s", a);
    string s;
    getchar();
    while (1)
    {
        getline(cin, s);
        if (s.compare("END") == 0)
            break;
        int n = s.size();
        for (int i = 0; i < n; i++)
        {
            if ((s[i] >= 'A' && s[i] <= 'Z') || (s[i] >= 'a' && s[i] <= 'z'))
            {
                int t = 0;
                for (; i < n; i++)
                {
                    if (!((s[i] >= 'A' && s[i] <= 'Z') || (s[i] >= 'a' && s[i] <= 'z')))
                        break;
                    a[t++] = s[i];
                }
                a[t] = '\0';
                it = m.find(a);
                if (it != m.end())
                    cout << it->second;
                else
                    printf("%s", a);
            }
            printf("%c", s[i]);
        }
        printf("\n");
    }
    return 0;
}
