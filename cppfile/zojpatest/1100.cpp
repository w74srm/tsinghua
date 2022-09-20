#include <iostream>
#include <vector>
#include <cstdio>
#include <cstring>
#include <string>
#include <algorithm>
#include <cmath>
using namespace std;

string lowrelation[13] = {"tret", "jan", "feb", "mar", "apr", "may", "jun", "jly", "aug", "sep", "oct", "nov", "dec"};
string highrelation[13] = {"", "tam", "hel", "maa", "huh", "tou", "kes", "hei", "elo", "syy", "lok", "mer", "jou"};

struct Mars
{
    string high, low;
    Mars() : high(""), low(""){};
};

int transform(Mars m)
{
    int sum = 0;
    for (int i = 0; i < 13; i++)
    {
        if (m.high == highrelation[i])
        {
            sum += i * 13;
            break;
        }
    }
    for (int i = 0; i < 13; i++)
    {
        if (m.low == lowrelation[i])
        {
            sum += i;
            break;
        }
    }
    return sum;
}

Mars transform(int n)
{
    Mars m;
    if (n % 13 != 0 || n == 0)
        m.low = lowrelation[n % 13];
    n /= 13;
    m.high = highrelation[n];
    return m;
}

void print(int i)
{
    cout << i << endl;
}

void print(Mars m)
{
    if (m.high != "" && m.low != "")
        cout << m.high << " " << m.low << endl;
    else if (m.high == "")
        cout << m.low << endl;
    else
        cout << m.high << endl;
}

int stringToInt(string s)
{
    int sum = 0;
    for (int i = 0; i < s.size(); i++)
    {
        sum += (s[i] - '0') * pow(10, s.size() - 1 - i);
    }
    return sum;
}

int main()
{
    int N;
    cin >> N;
    string temp;
    getchar();
    while (N--)
    {
        getline(cin, temp);
        if (temp < "999")
        {
            print(transform(stringToInt(temp)));
        }
        else
        {
            Mars m;
            int pos = temp.find(" ");
            if (pos < 0)
            {
                m.low = temp;
                for (int i = 0; i < 13; i++)
                {
                    if (m.low == highrelation[i])
                    {
                        m.high = m.low;
                        m.low = "";
                    }
                }
            }
            else
            {
                m.high = temp.substr(0, pos);
                m.low = temp.substr(pos + 1, temp.size() - pos - 1);
            }
            print(transform(m));
        }
    }
    return 0;
}