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
    // BFS
    // Time O(n)  Space O(n)
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if (NULL == root) return ans;
        queue<TreeNode*> Q;
        Q.push(root);
        while (!Q.empty()) {
            queue<TreeNode*> nextQ;
            vector<int> level;
            while (!Q.empty()) {
                TreeNode *t = Q.front();
                Q.pop();
                level.push_back(t->val);
                if (t->left) nextQ.push(t->left);
                if (t->right) nextQ.push(t->right);
            }
            ans.push_back(level);
            Q = nextQ;
        }
        return ans;
    }
};
