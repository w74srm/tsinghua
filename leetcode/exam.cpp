#include<bits/stdc++.h>
using namespace std;


void quicksort(vector<int> &nums, int left, int right, vector<vector<long long> >flight)
{
    if(left >= right) return;
    int base = nums[left];
    int i = left, j = right;
    while(i < j)
    {
        while(i < j && flight[nums[j]][1] >= flight[base][1]) j--;
        swap(nums[i], nums[j]);
        while(i < j && flight[nums[i]][1] <= flight[base][1]) i++;
        swap(nums[i], nums[j]);
    }
    quicksort(nums, left, i-1, flight);
    quicksort(nums, i+1, right, flight);
}


int main()
{
    int n;
    cin >> n;
    vector<vector<long long> > flight(n, vector<long long>(2, 0));
    for(int i = 0; i < n; i++)
    {
        cin >> flight[i][0] >> flight[i][1];
    }
    vector<int> nums(n, 0);
    for(int i = 0; i < n; i++)
    {
        nums[i] = i;
    }
    quicksort(nums, 0, n-1, flight);
    for(int i = 0; i < n; i++)
    {
        cout << nums[i] << ' ';
    }
    cout << endl;
    vector<int> index(n, 0);
    for(int i = 0; i < n; i++)
    {
        index[nums[i]] = i;
    }
    for(int i = 0; i < n; i++)
    {
        cout << flight[index[n-i-1]][0] << ' ' << flight[i][1] << endl;
    }
    return 0;
}