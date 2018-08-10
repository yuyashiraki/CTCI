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
    // PreOrder Recursion
    // Time O(n)  Space O(log(n))
    TreeNode* preOrder(TreeNode *root) {
        if (NULL == root || (NULL == root->left && NULL == root->right)) {
            return root;
        }
        TreeNode *left = preOrder(root->left);
        if (NULL == left) {
            return preOrder(root->right);
        }
        TreeNode *right = root->right;
        root->right = root->left;
        root->left = NULL;
        if (NULL == right) return left;
        left->right = right;
        return preOrder(right);

    }
    void flatten(TreeNode* root) {
        if (NULL == root) return;
        preOrder(root)->right = NULL;
    }
};
