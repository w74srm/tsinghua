#include <stdio.h>
int main()
{
    int x, y;
    while (scanf("%d%d", &x, &y) != EOF)
    {
        printf("%d\n\n", x + y); //注意两个换行符
    }
    return 0;
}