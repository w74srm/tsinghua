#include<bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> box(100);
    for(int i = 2; i < 100; i++)
    {
        for(int j = 1; j < 100; j++)
        {
            if(j%i==0) box[j] = 1 - box[j];
        }
    }
    return 0;
}