#include <iostream>
#include <map>
#include <vector>
#include <string>
using namespace std;
int M, N, S;
map<string, bool> msb;
vector<string> vs;
int main()
{
    scanf("%d%d%d", &M, &N, &S);
    vs.push_back(" ");
    string s;
    for (int i = 0; i < M; i++)
    {
        cin >> s;
        vs.push_back(s);
        msb[s] = false;
    }
    int i = S;
    if (vs.size() - 1 < S)
    {
        cout << "Keep going..." << endl;
        return 0;
    }
    while (i <= M)
    {
        if (msb[vs[i]] == false)
        {
            cout << vs[i] << endl;
            msb[vs[i]] = true;
            i += N;
        }
        else
        {
            i++;
        }
    }
    return 0;
}