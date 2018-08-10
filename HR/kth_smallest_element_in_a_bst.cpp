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
    // Time O(k)  Space O(height)
    TreeNode *kthSmallest2(TreeNode *root, int &k) {
        if (NULL == root) return NULL;
        TreeNode *l = kthSmallest2(root->left, k);
        if (l) return l;
        if (0 == --k) return root;
        TreeNode *r = kthSmallest2(root->right, k);
        return r;
    }
    int kthSmallest(TreeNode* root, int k) {
        if (NULL == root) {
            return 0;
        }
        return kthSmallest2(root, k)->val;
    }
};
