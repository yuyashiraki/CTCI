/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
// Divide and conquer
// Time O(n)  Space O(log(n))
class Solution {
public:
    TreeNode* recur(vector<int>& nums, int l, int r) {
        if (r <= l) return NULL;
        int m = l + (r - l) / 2;
        TreeNode *root = new TreeNode(nums[m]);
        root->left = recur(nums, l, m);
        root->right = recur(nums, m + 1, r);
        return root;
    }
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        TreeNode *root = recur(nums, 0, nums.size());
        return root;
    }
};
