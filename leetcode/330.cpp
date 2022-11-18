#include<bits/stdc++.h>
using namespace std;


int minPatches(vector<int>& nums, int n)
{
    int patches = 0;
    long long x = 1;
    int length = nums.size(), index = 0;
    while(x <= n)
    {
        if(index < length && nums[index] <= x)
        {
            x += nums[index];
            index++;
        }
        else
        {
            x <<= 1;
            patches++;
        }
    }
    return patches;
}


int main()
{
    int l, n;
    cin >> l >> n;
    vector<int> nums(l, 0);
    for(int i = 0; i < l; i++)
    {
        cin >> nums[i];
    }
    int result = minPatches(nums, n);
    cout << result << endl;
    return 0;
}