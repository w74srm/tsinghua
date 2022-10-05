#include<bits/stdc++.h>
using namespace std;


int finMin(vector<int>& nums)
{
    int left = 0, right = nums.size()-1;
    while(left < right)
    {
        int mid = left + (right - left) / 2;
        if(nums[mid] > nums[right]) left = mid + 1;
        else if(nums[mid] < nums[right]) right = mid;
        else right-=1;
    }
    return nums[left];
}


int main()
{
    int n;
    cin >> n;
    vector<int> nums(n, 0);
    for(int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }
    int ans = finMin(nums);
    cout << ans << endl;
    return 0;
}