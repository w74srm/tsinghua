#include <iostream>
#include <set>
#include <string>
#include <algorithm>
using namespace std;

int main()
{
    int N;
    cin >> N;
    string s;
    set<int> st;
    for (int i = 0; i < N; i++)
    {
        cin >> s;
        int sum = 0;
        for (int j = 0; j < s.size(); j++)
        {
            sum += s[j] - '0';
        }
        st.insert(sum);
    }
    cout << st.size() << endl;
    for (set<int>::iterator it = st.begin(); it != st.end(); it++)
    {
        if (it == st.begin())
        {
            cout << *it;
        }
        else
        {
            cout << " " << *it;
        }
    }
    return 0;
}