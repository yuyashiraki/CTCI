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
    // using BFS
    // Time O(n)  Space O(n)
    vector<vector<int>> levelOrder(TreeNode* root) {
        int level = 0;
        vector<vector<int>> ans;
        queue<pair<TreeNode*,int>> Q;
        Q.emplace(root,level);
        while (!Q.empty()) {
            TreeNode *cur = Q.front().first;
            level = Q.front().second;
            Q.pop();
            if (!cur) continue;
            if (ans.size() <= level) ans.push_back(vector<int>{cur->val});
            else ans[level].push_back(cur->val);
            Q.emplace(cur->left, level + 1);
            Q.emplace(cur->right, level + 1);
        }
        return ans;
    }
};
