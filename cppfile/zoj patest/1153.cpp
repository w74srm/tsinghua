#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>
using namespace std;

// 保存参试者的信息和最终要输出的结果
struct Node
{
    string str;
    int val;
};

bool nodeCmp(Node &t1, Node &t2)
{
    return t1.val == t2.val ? t1.str < t2.str : t1.val > t2.val;
}

int main()
{
    // 获取考生信息
    int n, m; // 输入和查询的数量
    cin >> n >> m;
    vector<Node> testees(n);
    for (int i = 0; i < n; i++)
        cin >> testees[i].str >> testees[i].val;

    // 获取要求并求解
    int type;
    string term;
    for (int caseIndex = 1; caseIndex <= m; caseIndex++)
    {
        // 获取要求
        cin >> type >> term;
        printf("Case %d: %d %s\n", caseIndex, type, term.c_str());

        // type为1和3时的结果
        vector<Node> results;
        switch (type)
        {
        case 1:
        {
            for (int i = 0; i < n; i++)
                if (testees[i].str[0] == term[0])
                    results.push_back(testees[i]);
            break;
        }
        case 2:
        {
            int testeeNum = 0, testeeScoreSum = 0;
            for (int i = 0; i < n; i++)
                if (testees[i].str.substr(1, 3) == term)
                {
                    testeeNum += 1;
                    testeeScoreSum += testees[i].val;
                }
            if (testeeNum == 0 && testeeScoreSum == 0)
                printf("NA\n");
            else
                printf("%d %d\n", testeeNum, testeeScoreSum);
            break;
        }
        case 3:
        {
            unordered_map<string, int> statistics;
            for (int i = 0; i < n; i++)
                if (testees[i].str.substr(4, 6) == term)
                    statistics[testees[i].str.substr(1, 3)] += 1;
            for (auto it : statistics)
                results.push_back({it.first, it.second});
        }
        }

        if (type == 1 || type == 3)
        {
            if (results.empty())
                printf("NA\n");
            else
            {
                sort(results.begin(), results.end(), nodeCmp);
                for (int i = 0; i < results.size(); i++)
                    printf("%s %d\n", results[i].str.c_str(), results[i].val);
            }
        }
    }
    return 0;
}
