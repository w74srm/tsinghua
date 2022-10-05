#include<bits/stdc++.h>
using namespace std;

int maxSum = INT16_MIN;


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};


int getMax(TreeNode* root)
{
    if(root == nullptr) return 0;
    int leftGain = max(getMax(root->left), 0);
    int rightGain = max(getMax(root->right), 0);

    int priceNewPath = leftGain + rightGain + root->val;

    maxSum = max(maxSum, priceNewPath);

    return root->val + max(leftGain, rightGain);
}


int maxPathSum(TreeNode* root)
{
    getMax(root);
    return maxSum;
}


int main()
{
    TreeNode* root = &TreeNode();
    int result = maxPathSum(root);
    cout << result <<endl;
    return 0;
}