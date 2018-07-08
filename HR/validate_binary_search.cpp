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
    bool rt = true;
    pair<int, int> dfs(TreeNode *root)
    {
        int sml, lg;
        if (!root->right) {
            lg = root->val;
        } else {
            pair<int, int> r = dfs(root->right);
            lg = r.second;
            if (root->val >= r.first) {
                rt = false;
            }
        }
        if (!root->left) {
            sml = root->val;
        } else {
            pair<int, int> l = dfs(root->left);
            sml =l.first;
            if (root->val <= l.second) {
                rt = false;
            }
        }
        return make_pair(sml, lg);
    }
    bool isValidBST(TreeNode* root) {
        if (!root) {
            return true;
        }
        dfs(root);
        return rt;
    }
};
