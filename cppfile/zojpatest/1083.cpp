#include <iostream>

using namespace std;

struct Student
{
    string name;
    string ID;
    int grade;
};

Student stu[105];
int main()
{
    int N;
    int grade_low, grade_high;
    int *list1 = new int[105]();
    cin >> N;
    for (int i = 1; i <= N; i++)
    {
        cin >> stu[i].name >> stu[i].ID >> stu[i].grade;
        list1[stu[i].grade] = i;
    }
    cin >> grade_low >> grade_high;
    int count = 0;
    for (int i = grade_high; i >= grade_low; i--)
        if (list1[i])
        {
            count++;
            cout << stu[list1[i]].name << ' ' << stu[list1[i]].ID << endl;
        }

    if (!count)
        cout << "NONE" << endl;

    return 0;
}