/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 // Preorder Traversal
 // Time O(n)  Space O(height)
class Solution {
public:
    TreeNode *prev = NULL;
    void flatten(TreeNode* root) {
        if (NULL == root) return;
        if (NULL != prev) prev->right = root;
        TreeNode *right = root->right;
        //cout << root->val << endl;
        prev = root;
        flatten(root->left);
        root->left = NULL;
        flatten(right);
    }
};
