#include <iostream>
#include <string>
#include <vector>
using namespace std;

vector<int> PPos, APos, TPos;
string s;

int main()
{
    int num = 0;
    cin >> s;
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == 'P')
            PPos.push_back(i);
        if (s[i] == 'A')
            APos.push_back(i);
        if (s[i] == 'T')
            TPos.push_back(i);
    }
    int PSize = PPos.size(),
        ASize = APos.size(),
        TSize = TPos.size(),
        PIndex = 0,
        TIndex = 0;
    for (int i = 0; i < ASize; i++)
    {
        while (PIndex < PSize && PPos[PIndex] < APos[i])
        {
            PIndex++;
        }
        while (TIndex < TSize && TPos[TIndex] < APos[i])
        {
            TIndex++;
        }
        if (TIndex >= TSize)
            break;
        num += PIndex * (TSize - TIndex);
        num = num % 1000000007;
    }
    cout << num << endl;
    return 0;
}