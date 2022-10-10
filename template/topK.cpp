#include<bits/stdc++.h>
using namespace std;


void getK(vector<int> &nums, int left, int right, int k)
{
    if(left >= right) return;
    int base = nums[left];
    int i = left, j = right;
    while(i < j)
    {
        while(i < j && nums[j] >= base) j--;
        swap(nums[i], nums[j]);
        while(i < j && nums[i] <= base) i++;
        swap(nums[i], nums[j]);
    }
    if(nums.size() - i < k) getK(nums, left, i-1, k);
    else getK(nums, i+1, right, k);
}


int main()
{
    int n, k;
    cin >> n >> k;
    vector<int> nums(n, 0);
    for(int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }
    getK(nums, 0, n-1, k);
    cout << nums[n - k];
    return 0;
}