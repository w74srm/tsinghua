#include <iostream>
#include <bits/stdc++.h>
using namespace std;
//对S进行倒置操作
string rev(string s)
{
    reverse(s.begin(), s.end()); //algorithm头文件里面的函数reverse(s.begin(), s.end())直接对s进行倒置
    return s;
}
string add(string s1, string s2)
{
    string s = s1;
    int carry = 0;
    for (int i = s1.size() - 1; i >= 0; i--)
    {
        //s2实际上是s1的倒置
        s[i] = (s1[i] - '0' + s2[i] - '0' + carry) % 10 + '0';
        carry = (s1[i] - '0' + s2[i] - '0' + carry) / 10;
    }
    if (carry > 0)
        s = "1" + s; //1是在最高位上
    return s;
}
int main()
{
    string s, sum;
    int n = 10;
    cin >> s;
    if (s == rev(s))
    {
        cout << s << " is a palindromic number.\n";
        return 0;
    }
    while (n--)
    {
        sum = add(s, rev(s));
        cout << s << " + " << rev(s) << " = " << sum << endl;
        if (sum == rev(sum))
        {
            cout << sum << " is a palindromic number.\n";
            return 0;
        }
        s = sum;
    }
    cout << "Not found in 10 iterations.\n";
    return 0;
}