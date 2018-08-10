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
    // DFS
    // Time O(n)  Space O(height)
    bool isValidBST(TreeNode *root, long long sml, long long lrg) {
        if (NULL == root) return true;
        bool ans = true;
        ans &= root->val > sml && root->val < lrg;
        ans &= isValidBST(root->left, sml, root->val);
        ans &= isValidBST(root->right, root->val, lrg);
        return ans;
    }
    bool isValidBST(TreeNode* root) {
        return isValidBST(root, LLONG_MIN, LLONG_MAX);
    }
};
