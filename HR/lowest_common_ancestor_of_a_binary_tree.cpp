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
    TreeNode *dfs(TreeNode* cur, TreeNode *p, TreeNode *q) {
        if (cur == q || cur == p) {
            return cur;
        }
        TreeNode *l = NULL, *r = NULL;
        if (cur->left) l = dfs(cur->left, p, q);
        if (cur->right) r = dfs(cur->right, p, q);
        if (l && r) {
            return cur;
        } else if (l) {
            return l;
        } else {
            return r;
        }
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        return dfs(root, p, q);
    }
};
