#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int N;
    vector<int> v1, v2;
    int n;
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        cin >> n;
        v1.push_back(n);
    }
    for (int i = 0; i < N; i++)
    {
        cin >> n;
        v2.push_back(n);
    }
    bool flag = false;
    int step = 0;
    for (int i = 0; i < N - 1; i++)
    {
        if (v2[i] <= v2[i + 1])
            continue;
        else
        {
            for (int j = i + 1; j < N; j++)
            {
                step = i + 1;
                if (v2[j] != v1[j])
                {
                    flag = true;
                    break;
                }
            }
            break;
        }
    }
    if (flag)
    {
        bool flag1 = false;
        cout << "Merge Sort" << endl;
        int len = v2.size();
        int i;
        for (i = 2; i <= step; i *= 2)
        {
            if (!flag1)
                for (int j = 0; j < len; j += i)
                {
                    sort(v1.begin() + j, v1.begin() + min(i + j, len));
                }
            int k;
            for (k = 0; k < N; k++)
            {
                if (v1[k] == v2[k])
                    continue;
                else
                {
                    break;
                }
            }
            if (k == N)
            {
                flag1 = true;
                break;
            }
        }
        if (flag1)
            step = 2 * i;
        for (int i = 0; i < len; i += step)
        {
            sort(v2.begin() + i, v2.begin() + min(step + i, len));
        }
        for (int i = 0; i < N; i++)
        {
            cout << v2[i];
            if (i != N - 1)
                cout << " ";
            else
                cout << endl;
        }
    }
    else
    {
        cout << "Insertion Sort" << endl;
        for (int i = step - 1; i >= 0; i--)
        {
            if (v2[step] >= v2[i])
            {
                int temp = v2[step];
                for (int j = step; j > i + 1; j--)
                {
                    v2[j] = v2[j - 1];
                }
                v2[i + 1] = temp;
                break;
            }
            if (v2[step] < v2[0])
            {
                int temp = v2[step];
                for (int j = step; j > 0; j--)
                {
                    v2[j] = v2[j - 1];
                }
                v2[0] = temp;
                break;
            }
        }
        for (int i = 0; i < N; i++)
        {
            cout << v2[i];
            if (i != N - 1)
                cout << " ";
            else
                cout << endl;
        }
    }
    return 0;
}