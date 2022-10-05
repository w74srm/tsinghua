#include<bits/stdc++.h>
using namespace std;


unordered_map<int, vector<string>> ans;
unordered_set<string> wordSet;


void backtrack(const string& s, int index) {
    if (!ans.count(index)) {
        if (index == s.size()) {
            ans[index] = {""};
            return;
        }
        ans[index] = {};
        for (int i = index + 1; i <= s.size(); ++i) {
            string word = s.substr(index, i - index);
            if (wordSet.count(word)) {
                backtrack(s, i);
                for (const string& succ: ans[i]) {
                    ans[index].push_back(succ.empty() ? word : word + " " + succ);
                }
            }
        }
    }
}


vector<string> wordBreak(string s, vector<string>& wordDict) {
    wordSet = unordered_set<string>(wordDict.begin(), wordDict.end());
    backtrack(s, 0);
    return ans[0];
}


int main()
{
    int n;
    cin >> n;
    vector<string> wordDict;
    for(int i = 0; i < n; i++)
    {
        string temp;
        cin >> temp;
        wordDict.push_back(temp);
    }
    string s;
    cin >> s;
    vector<string> res = wordBreak(s, wordDict);
    for(int i = 0; i < res.size(); i++)
    {
        cout << res[i];
    }
    return 0;
}

