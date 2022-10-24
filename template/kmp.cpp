#include<bits/stdc++.h>
using namespace std;


void getNext(vector<int>& next, string pattern)
{
    int n = pattern.length();
    int i = 0, j = -1;
    while(i < n - 1)
    {
        if(j==-1||pattern[i] == pattern[j])
        {
            i++;
            j++;
            next[i] = j;
        }
        else
        {
            j = next[j];
        }
    }
}


int kmp(string s, string t)
{
    int i = 0, j = 0;
    vector<int> next(t.length());
    getNext(next, t);
    while(i < s.length() && j < t.length())
    {
        if(j == -1 || s[i] == t[j])
        {
            i++;
            j++;
        }
        else j = next[j];
    }
    if(j >= t.length()) return (i - t.length());
    else return -1;
}


int main()
{
    string s, t;
    cin >> s;
    cin >> t;
    int r = kmp(s, t);
    cout << r << endl;
    return 0;
}