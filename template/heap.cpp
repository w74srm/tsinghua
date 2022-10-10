#include<bits/stdc++.h>
using namespace std;


void HeapAdjust(vector<int> &nums, int start, int end)
{
    int tmp = nums[start];
    for(int i = 2 * start + 1; i <= end; i = i * 2 + 1)
    {
        if(i < end && nums[i + 1] > nums[i]) i++;
        if (nums[i] > tmp)
        {
            nums[start] = nums[i];
            start = i;
        }
        else break;
    }
    nums[start] = tmp;
}


void heapSort(vector<int> &nums, int length)
{
    for(int i = length / 2 - 1 ; i >= 0; i--)
    {
        HeapAdjust(nums, i, length - 1);
    }
    int tmp;
    for(int i = 0; i < length-1; i++)
    {
        swap(nums[0], nums[length-1-i]);
        HeapAdjust(nums, 0, length-1-i-1);
    }
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
    heapSort(nums, n);
    for(int i = 0; i < n; i++)
    {
        cout << nums[i] << " ";
    }
    return 0;
}