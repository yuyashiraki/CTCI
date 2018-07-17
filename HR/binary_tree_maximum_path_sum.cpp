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
    // Traverse tree by recursion
    // Time O(n) Space O(log(n))
    int maxsum = INT_MIN;
    int recur(TreeNode *root) {
        if (NULL == root) return 0;
        int l = recur(root->left);
        int r = recur(root->right);
        int ans = max(root->val, max(root->val + l, root->val + r));
        maxsum = max(maxsum, max(ans, root->val + r + l));
        return ans;
    }
    int maxPathSum(TreeNode* root) {
        recur(root);
        return maxsum;
    }
};
