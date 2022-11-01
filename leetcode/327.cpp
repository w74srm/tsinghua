#include<bits/stdc++.h>
using namespace std;


struct SegNode
{
    int lo, hi, add;
    SegNode *lchild, *rchild;
    SegNode(int left, int right): lo(left), hi(right), add(0), lchild(nullptr), rchild(nullptr) {}
};


SegNode* build(int left, int right)
{
    SegNode* node = new SegNode(left, right);
    if(left == right)
    {
        return node;
    }
    int mid = (left + right) / 2;
    node->lchild = build(left, mid);
    node->rchild = build(mid+1, right);
    return node;
}


void insert(SegNode* root, int val)
{
    root->add++;
    if (root->lo == root->hi) return;
    int mid = (root->lo + root->hi) / 2;
    if(val <= mid) insert(root->lchild, val);
    else insert(root->rchild, val);
}


int count(SegNode* root, int left, int right)
{
    if(left > root->hi || right < root->lo) return 0;
    if(left <= root->lo && root->hi <= right) return root->add;
    return count(root->lchild, left, right) + count(root->rchild, left, right);
}


int countRangeSum(vector<int>& nums, int lower, int upper)
{
    long long sum = 0;
    vector<long long> preSum = {0};
    for(int i = 0; i < nums.size(); i++)
    {
        sum += nums[i];
        preSum.push_back(sum);
    }
    set<long long> allNumbers;
    for(int i = 0; i < preSum.size(); i++)
    {
        allNumbers.insert(preSum[i]);
        allNumbers.insert(preSum[i] - lower);
        allNumbers.insert(preSum[i] - upper);
    }
    unordered_map<long long, int> values;
    int idx = 0;
    for(long long x: allNumbers)
    {
        values[x] = idx;
        idx++;
    }

    SegNode* root = build(0, values.size() - 1);
    int result = 0;
    for(int i = 0; i < preSum.size(); i++)
    {
        int left = values[preSum[i] - upper], right = values[preSum[i] - lower];
        result += count(root, left, right);
        insert(root, values[preSum[i]]);
    }
    return result;
}


int main()
{
    int n, lower, upper;
    cin >> n >> lower >> upper;
    vector<int> nums(n, 0);
    for(int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }
    cout << countRangeSum(nums, lower, upper) << endl;
    return 0;
}