#include<bits/stdc++.h>
using namespace std;


void quicksort(vector<int> &nums, int left, int right)
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
    quicksort(nums, left, i-1);
    quicksort(nums, i+1, right);
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
    quicksort(nums, 0, n-1);
    for(int i = 0; i < n; i++)
    {
        cout << nums[i] << endl;
    }
    return 0;
}