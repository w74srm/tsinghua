#include <iostream>
#include <vector>
#include <string>
using namespace std;

struct pwd
{
    string name;
    string password;
};

const int maxn = 1005;
pwd input[maxn];
vector<pwd> output;

int modified(string &str)
{
    int flag = 0;
    for (int i = 0; i < str.length(); i++)
    {
        switch (str[i])
        {
        case '1':
            str[i] = '@';
            flag = 1;
            break;

        case '0':
            str[i] = '%';
            flag = 1;
            break;

        case 'l':
            str[i] = 'L';
            flag = 1;
            break;

        case 'O':
            str[i] = 'o';
            flag = 1;
            break;
        }
    }
    return flag;
}

int main()
{
    int N;
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        cin >> input[i].name >> input[i].password;
    }
    for (int i = 0; i < N; i++)
    {
        if (modified(input[i].password) == 1)
        {
            output.push_back(input[i]);
        }
    }
    int cnt = output.size();
    if (cnt != 0)
    {
        cout << cnt << endl;
        for (int i = 0; i < cnt; i++)
        {
            cout << output[i].name << ' ' << output[i].password << endl;
        }
    }
    else
    {
        if (N == 1)
            cout << "There is 1 account and no account is modified" << endl;
        else
            cout << "There are " << N << " accounts and no account is modified" <<endl;
    }
    return 0;
}