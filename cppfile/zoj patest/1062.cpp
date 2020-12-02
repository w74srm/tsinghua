#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

struct person
{
    int id;
    int virtue;
    int talent;
    int classes; //0:sages 1:nobleman 2:foolman 3:small man
};

vector<person> persons;

bool cmp(person a, person b)
{
    if (a.classes < b.classes)
        return true;
    else if (a.classes > b.classes)
        return false;
    else
    {
        int total_a = a.virtue + a.talent;
        int total_b = b.virtue + b.talent;
        if (total_a > total_b)
            return true;
        else if (total_a < total_b)
            return false;
        else
        {
            if (a.virtue > b.virtue)
                return true;
            else if (a.virtue < b.virtue)
                return false;
            else
            {
                return a.id < b.id ? true : false;
            }
        }
    }
}

int main()
{
    int n, baseline, highline;
    cin >> n >> baseline >> highline;
    for (int i = 0; i < n; i++)
    {
        int num, v, t;
        cin >> num >> v >> t;
        if (v >= baseline && t >= baseline)
        {
            person p;
            p.id = num;
            p.virtue = v;
            p.talent = t;
            if (v >= highline && t >= highline)
                p.classes = 0;
            else if (v >= highline && t < highline)
                p.classes = 1;
            else if (v < highline && t < highline && v >= t)
                p.classes = 2;
            else
                p.classes = 3;
            persons.push_back(p);
        }
    }
    sort(persons.begin(), persons.end(), cmp);
    cout << persons.size() << endl;
    for (int i = 0; i < persons.size(); i++)
    {
        cout << persons[i].id << " " << persons[i].virtue << " " << persons[i].talent << endl;
    }
    return 0;
}