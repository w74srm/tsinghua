#include <cstdio>
#include <iostream>
#include <cstring>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

struct stu
{
    int ID, GE, GI, rank;
    vector<int> choices;
    int sum()
    {
        return GE + GI;
    }
    bool operator<(stu s)
    {
        if (sum() != s.sum())
            return sum() > s.sum();
        else
            return GE > s.GE;
    }
}; //重载小于号制定比较规则

int main()
{
    int N, M, K;
    cin >> N >> M >> K;
    vector<int> quota;
    int QUOTA;
    for (int i = 0; i < M; i++)
    {
        cin >> QUOTA;
        quota.push_back(QUOTA);
    } //存储各个学校的指标
    stu st;
    int choice;
    vector<stu> v;
    for (int i = 0; i < N; i++)
    {
        st.ID = i;
        cin >> st.GE >> st.GI;
        st.choices.clear();
        for (int j = 0; j < K; j++)
        {
            cin >> choice;
            st.choices.push_back(choice);
        }
        v.push_back(st);
    }                         //将每个学生的填报情况存储到容器中
    sort(v.begin(), v.end()); //将学生按照分数非递增排序
    int oldrank = 1;
    for (int i = 0; i < v.size(); i++)
    {
        if (!i || v[i].sum() == v[i - 1].sum() && v[i].GE == v[i - 1].GE)
        {
            v[i].rank = oldrank;
        }
        else
        {
            v[i].rank = i + 1;
            oldrank = i + 1;
        }
    }                                                        //对学生进行排名，注意所写代码一定要能够完全反映题意
    vector<int> *schooladmissionResult = new vector<int>[M]; //为每个学校设一个录取信息容器
    int i = 0;
    int firststurank, firstschool; //这个是为了处理同名次并且报同一学校的问题
    bool flag = false;             //若该同学已被录取直接处理下一个同学
    while (i < N)
    {
        flag = false;
        for (int j = 0; j < K; j++)
        {
            int school = v[i].choices[j];
            if (quota[school])
            {
                schooladmissionResult[school].push_back(v[i].ID);
                flag = true;
                firstschool = school;
                firststurank = v[i].rank;
                quota[school]--;
                int temp = 0;
                int x;
                for (x = i + 1; x < N; x++)
                    if (v[x].rank == firststurank && v[x].choices[j] == firstschool)
                    {
                        schooladmissionResult[school].push_back(v[x].ID);
                        temp++;
                    }
                if (quota[school] > temp)
                {
                    quota[school] -= temp;
                }
                else
                    quota[school] = 0;
                if (temp)
                {
                    i += temp;
                }
                i++;
            }
            if (flag)
                break;
            if (j == K - 1)
                i++;
        }
    }

    for (int i = 0; i < M; i++)
    {
        if (schooladmissionResult[i].size())
        {
            sort(schooladmissionResult[i].begin(), schooladmissionResult[i].end());
            for (int j = 0; j < schooladmissionResult[i].size(); j++)
            {
                cout << schooladmissionResult[i][j];
                if (j != schooladmissionResult[i].size() - 1)
                    cout << " ";
                else
                    cout << endl;
            }
        }
        else
            cout << endl;
    }
    return 0;
}