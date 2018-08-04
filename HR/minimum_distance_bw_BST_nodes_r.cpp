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
    // Time O(n)  Space O(log(n))
    int ans = INT_MAX;
    pair<int, int> recur(TreeNode* root) {
        pair<int, int> rt;
        rt.first = rt.second = root->val;
        if (root->left) {
            pair<int, int> l = recur(root->left);
            ans = min(ans, root->val - l.second);
            rt.first = l.first;
        }
        if (root->right) {
            pair<int, int> r = recur(root->right);
            ans = min(ans, r.first - root->val);
            rt.second = r.second;
        }
        return rt;
    }
    int minDiffInBST(TreeNode* root) {
        recur(root);
        return ans;
    }
};
