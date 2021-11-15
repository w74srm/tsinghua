/*
注意进出栈的顺序，先进后出 
*/
#include <iostream>
#include <stack>
using namespace std;
struct Matrix
{
    int a, b;
    Matrix(int a = 0, int b = 0) : a(a), b(b)
    {
    }
} m[26];
stack<Matrix> s;
int main()
{
    int n;
    cin >> n;
    while (n--)
    {
        char w;
        cin >> w;
        cin >> m[w - 'A'].a >> m[w - 'A'].b;
    }
    string ex;
    while (cin >> ex)
    {
        int len = ex.length();
        bool error = false;
        int sum = 0;
        for (int i = 0; i < len; i++)
        {
            if (isalpha(ex[i]))
            {
                s.push(m[ex[i] - 'A']);
            }
            else if (ex[i] == ')')
            {
                Matrix x = s.top(); //B
                s.pop();
                Matrix y = s.top(); //A
                s.pop();
                if (x.a != y.b)
                {
                    error = true;
                    break;
                }
                else
                {
                    sum += (y.a * y.b * x.b);
                    s.push(Matrix(y.a, x.b));
                }
            }
        }
        if (error)
        {
            cout << "error" << endl;
        }
        else
        {
            cout << sum << endl;
        }
    }
}