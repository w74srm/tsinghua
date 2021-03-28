#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <algorithm>
using namespace std;

struct School
{
    string name;
    int score, member, rank;
};
bool cmp(School a, School b)
{
    if (a.score != b.score)
        return a.score > b.score;
    else if (a.member != b.member)
        return a.member < b.member;
    else
        return a.name < b.name;
}
map<string, int> member;
map<string, double> school;
string toLower(string a)
{
    for (int i = 0; i < a.length(); i++)
    {
        a[i] = tolower(a[i]);
    }
    return a;
}
int main()
{
    int n, tmpscore, cnt = 1, same = 1;
    string tmpid, tmpschool;
    scanf("%d", &n);
    vector<School> v;
    set<string> sc;
    for (int i = 0; i < n; i++)
    {
        cin >> tmpid >> tmpscore >> tmpschool;
        tmpschool = toLower(tmpschool);
        sc.insert(tmpschool);
        if (tmpid[0] == 'T')
            school[tmpschool] += (tmpscore * 1.5);
        else if (tmpid[0] == 'A')
            school[tmpschool] += tmpscore;
        else
            school[tmpschool] += (tmpscore / 1.5);
        member[tmpschool]++;
    }
    for (auto it : sc)
    {
        School tmp;
        tmp.name = it;
        tmp.score = (int)school[it];
        tmp.member = member[it];
        v.push_back(tmp);
    }
    sort(v.begin(), v.end(), cmp);
    printf("%d\n", v.size());
    for (int i = 0; i < v.size(); i++)
    {
        if (i == 0)
            cout << cnt << " " << v[i].name << " " << v[i].score << " " << v[i].member << endl;
        else
        {
            if (v[i].score != v[i - 1].score)
            {
                cnt += same;
                same = 1;
            }
            else
                same++;
            cout << cnt << " " << v[i].name << " " << v[i].score << " " << v[i].member << endl;
        }
    }
    system("pause");
    return 0;
}
