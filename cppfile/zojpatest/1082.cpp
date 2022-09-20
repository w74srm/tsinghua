#include <cstdio>
#include <iostream>
#include <string>
using namespace std;

string digit[10] = {"ling", "yi", "er", "san", "si", "wu", "liu", "qi", "ba", "jiu"};
string unit[] = {"Shi", "Bai", "Qian", "Wan", "Yi"};

int main()
{
    string s;
    getline(cin, s);
    int n = s.size(), left = 0, right = s.size() - 1;
    if (s[0] == '-')
    {
        cout << "Fu";
        left++;
    }
    while (left + 4 <= right)
        right -= 4;
    while (left < n)
    {
        bool flag = false;
        bool isPrint = false;
        while (left <= right)
        {
            if (left > 0 && s[left] == '0')
                flag = true;
            else
            {
                if (flag)
                    cout << " ling";
                flag = false;
                if (left > 0)
                    cout << " ";
                cout << digit[s[left] - '0'];
                isPrint = true;
                if (left != right)
                    cout << " " << unit[right - left - 1];
            }
            left++;
        }
        if (isPrint && right != n - 1)
            cout << " " << unit[(n - 1 - right) / 4 + 2];
        right += 4;
    }
    return 0;
}
