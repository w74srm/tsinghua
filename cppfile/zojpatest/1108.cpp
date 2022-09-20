#include <iostream>
#include <string>
using namespace std;
bool isLegal(string &s, float &num);
bool isChar(char c);
int main()
{
    int N, cnt = 0;
    float sum = 0;
    string s;
    scanf("%d", &N);
    for (int i = 0; i < N; i++)
    {
        cin >> s;
        float num;
        if (isLegal(s, num))
        {
            sum += num;
            cnt++;
        }
        else
        {
            printf("ERROR: ");
            cout << s;
            printf(" is not a legal number\n");
        }
    }
    if (cnt > 1)
        printf("The average of %d numbers is %.2f\n", cnt, sum / cnt * 1.0);
    else if (cnt == 1)
        printf("The average of 1 number is %.2f\n", sum);
    else
        printf("The average of 0 numbers is Undefined\n");
    return 0;
}
bool isLegal(string &s, float &num)
{
    bool flag = false;
    int cnt1 = 0, cnt2 = 0; //分别记录'.'和小数部分的数字数量
    if (s[0] == '-')
        flag = true;
    for (int i = 0; i < s.length(); i++)
    {
        if (flag)
        {
            flag = false;
            continue;
        }
        if (isChar(s[i]) && s[i] != '.')
            return false;
        else if (s[i] == '.')
        {
            cnt1++;
            if (cnt1 > 1)
                return false;
        }
        else if (cnt1 == 1)
        {
            cnt2++;
            if (cnt2 > 2)
                return false;
        }
    }
    num = stof(s);
    return (num >= -1000 && num <= 1000) ? true : false;
}
bool isChar(char c)
{
    if (c >= '0' && c <= '9')
        return false;
    else
        return true;
}