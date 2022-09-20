#include <iostream>
#include <string>
#include <vector>
using namespace std;

struct student
{
    string name;
    string ID;
    char gender;
    int grade;
};

int main()
{
    vector<student> malestudent, femalestudent;
    int N;
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        student temp;
        cin >> temp.name >> temp.gender >> temp.ID >> temp.grade;
        if (temp.gender == 'F')
            femalestudent.push_back(temp);
        else
            malestudent.push_back(temp);
    }
    int num_male = malestudent.size();
    int num_female = femalestudent.size();
    int male_min = 100, female_max = 0;
    int index_female = 0, index_male = 0;
    for (int i = 0; i < num_female; i++)
    {
        if (femalestudent[i].grade > female_max)
        {
            index_female = i;
            female_max = femalestudent[i].grade;
        }
    }
    for (int i = 0; i < num_male; i++)
    {
        if (malestudent[i].grade < male_min)
        {
            index_male = i;
            male_min = malestudent[i].grade;
        }
    }
    if (num_female == 0)
    {
        cout << "Absent" << endl;
    }
    else
    {
        cout << femalestudent[index_female].name << ' ' << femalestudent[index_female].ID << endl;
    }
    if (num_male == 0)
    {
        cout << "Absent" << endl;
    }
    else
    {
        cout << malestudent[index_male].name << ' ' << malestudent[index_male].ID << endl;
    }
    if (num_female == 0 || num_male == 0)
        cout << "NA" << endl;
    else
        cout << female_max - male_min << endl;
    return 0;
}