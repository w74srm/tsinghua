#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

const int maxn = 10005;
string input[maxn];

bool cmp(string a, string b)
{
    return a + b < b + a;
}

int main()
{
    int N;
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        cin >> input[i];
    }
    sort(input, input + N, cmp);
    string result = "";
    for (int i = 0; i < N; i++)
    {
        result += input[i];
    }
    while (result[0] == '0')
    {
        result.erase(result.begin());
    }
    if(result.length()!=0)cout<<result<<endl;
    else cout<<0<<endl;
    return 0;
}