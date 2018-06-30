/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* recur(vector<int>& nums, int l, int r)
    {
        if (r < l) return NULL;
        int m = (l + r) / 2;
        TreeNode *root = new TreeNode(nums[m]);
        root->left = recur(nums, l, m - 1);
        root->right = recur(nums, m + 1, r);
        return root;
    }
    TreeNode* sortedArrayToBST(vector<int>& nums)
    {
        TreeNode *root = recur(nums, 0, nums.size() - 1);
        return root;
    }
};
