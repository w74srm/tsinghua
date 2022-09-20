#include <stdio.h>
#include <string>
#include <iostream>
using namespace std;
bool HASH[100] = {false}, HASH1[100] = {false};
int main()
{
    int k;
    string str, str1;
    cin >> k >> str;
    str1 = str;
    for (int i = 0; i < str.length();)
    {
        int num = 0;
        for (int j = i; j < str.length(); j++)
        {
            if (str[j] == str[i])
            {
                num++;
            }
            else
            {
                break;
            }
        }
        if (num % k != 0)
        {
            HASH[str[i]] = true;
        }
        i = i + num;
    }
    for (int i = 0; i < str.length();)
    {
        int num = 0;
        for (int j = i; j < str.length(); j++)
        {
            if (str[j] == str[i])
            {
                num++;
            }
            else
            {
                break;
            }
        }
        if (num % k != 0)
        {
            HASH[str[i]] = true;
            i = i + num;
        }
        else
        {
            if (HASH[str[i]] == false)
            {
                if (HASH1[str[i]] == false)
                {
                    cout << str[i];
                    HASH1[str[i]] = true;
                }
                str.erase(str.begin() + i + 1, str.begin() + i + k);
            }
            i++;
        }
    }
    if (str1 != str)
        printf("\n");
    cout << str;
    return 0;
}