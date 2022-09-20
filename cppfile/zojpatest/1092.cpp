#include <cstdio>
#include <iostream>
#include <cstring>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    string s1, s2;
    cin >> s1 >> s2;
    int len1 = s1.size();
    bool *hashtable1 = new bool[len1];
    fill(hashtable1, hashtable1 + len1, false);
    int len2 = s2.size();
    int count = 0;
    for (int i = 0; i < len2; i++)
    {
        for (int j = 0; j < len1; j++)
        {
            if (s1[j] == s2[i])
            {
                if (!hashtable1[j])
                {
                    hashtable1[j] = true;
                    count++;
                    break;
                }
            }
        }
    }

    if (len2 == count)
    {
        cout << "Yes " << len1 - count << endl;
    }
    else
        cout << "No " << len2 - count << endl;
    return 0;
}