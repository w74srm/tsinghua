#include <cstdio>
using namespace std;

int main()
{
    char str1[100];
    char str2[100];
    bool brokenkeys[40];
    char output[40];
    int i, j = 0;
    for (i = 0; i < 40; i++)
        brokenkeys[i] = false;
    scanf("%s%s", str1, str2);
    char *p1 = str1;
    char *p2 = str2;
    while (*p1 != '\0')
    {
        if (*p1 != *p2)
        {
            if (*p1 >= '0' && *p1 <= '9' && !brokenkeys[*p1 - '0'])
            {
                brokenkeys[*p1 - '0'] = true;
                ;
                output[j++] = *p1;
            }
            else if (*p1 >= 'a' && *p1 <= 'z' && !brokenkeys[10 + *p1 - 'a'])
            {
                brokenkeys[10 + *p1 - 'a'] = true;
                output[j++] = *p1 - 'a' + 'A';
            }
            else if (*p1 >= 'A' && *p1 <= 'Z' && !brokenkeys[10 + *p1 - 'A'])
            {
                brokenkeys[10 + *p1 - 'A'] = true;
                output[j++] = *p1;
            }
            else if (*p1 == '_' && !brokenkeys[36])
            {
                brokenkeys[36] = true;
                output[j++] = '_';
            }
        }
        else
            p2++;
        p1++;
    }
    output[j] = '\0';
    printf("%s\n", output);
    return 0;
}