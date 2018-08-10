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
    int diameterOfBinaryTree(TreeNode* root, int &ans) {
        if (NULL == root) return 0;
        int l = diameterOfBinaryTree(root->left, ans);
        int r = diameterOfBinaryTree(root->right, ans);
        ans = max(ans, l+r);
        return max(l, r)+1;
    }
    int diameterOfBinaryTree(TreeNode* root) {
        if (NULL == root) return 0;
        int ans = 0;
        diameterOfBinaryTree(root, ans);
        return ans;
    }
};
