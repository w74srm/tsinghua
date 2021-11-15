#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;
 
struct dic
{
    int n ;
    char str[10];
};
dic num[110];
 
bool cmp(char c, char b)
{
    return c > b;
}
 
bool cpm(dic str, dic n)
{
    return strcmp(str.str, n.str) < 0;
}
int main()
{
    char ch[10];
    char s[10];
    char ac[110][10];
    int i, j,total=0;
    while(~scanf("%s",ch)&&strcmp(ch, "XXXXXX")!=0)
    {
        strcpy(num[total++].str, ch);
        //i++;
    }
    sort(num, num+total, cpm);
    //printf("%d\n", total);
    while(~scanf("%s",ch),strcmp(ch, "XXXXXX")!=0)
    {
        int flag=0 ,len;
        int nel=strlen(ch);
        sort(ch, ch+nel, cmp);
        for(i=0; i<=total; i++)
        {
               strcpy(s, num[i].str);
            len = strlen(s);
            sort(s, s+len, cmp);
            if(strcmp(s, ch) == 0)
            {
                printf("%s\n", num[i].str);
                flag++;
            }
            //else
            //printf("NOT A VALID WORD\n");
        }
        if(flag==0)
        printf("NOT A VALID WORD\n");
          /*else
        {
            sort(ac,ac+flag,cpm);
            for(i=0; i<flag; i++)
            printf("%s", ac[i]);
        }*/
        printf("******\n");
    }
    return 0;
}