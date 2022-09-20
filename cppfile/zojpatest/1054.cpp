#include <iostream>
using namespace std;

const int maxc = 1<<24;
int cnt[maxc];

int main()
{
    int M, N;
    cin >> M >> N;
    int standard = M * N / 2;
    for (int i = 0 ; i < N ;i++)
    {
        for(int j = 0; j < M; j++)
        {
            int temp;
            cin>> temp;
            cnt[temp]++;
            if(cnt[temp]>standard)
            {
                cout<<temp;
            }
        }
    }
    return 0;
}