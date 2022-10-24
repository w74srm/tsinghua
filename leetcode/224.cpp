#include<bits/stdc++.h>
using namespace std;


int calculate(string s)
{
    stack<int> ops;
    ops.push(1);
    int sign = 1;

    int result = 0;
    int n = s.length();
    int i = 0;
    while(i < n)
    {
        switch (s[i])
        {
        case ' ':
            i++;
            break;
        case '+':
            sign = ops.top();
            i++;
            break;
        case '-':
            sign = -ops.top();
            i++;
            break;
        case '(':
            ops.push(sign);
            i++;
            break;
        case ')':
            ops.pop();
            i++;
            break;
        default:
            long num = 0;
            while(i < n && s[i] >= '0' && s[i] <= '9')
            {
                num = num * 10 + s[i] - '0';
                i++;
            }
            result += sign * num;
            break;
        }
    }
    return result;
}


int main()
{
    string s;
    cin >> s;
    int r = calculate(s);
    cout << r << endl;
    return 0;
}