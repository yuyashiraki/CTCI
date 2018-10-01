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
    // BFS keeping position of each node
    // Time O(n)  Space O(n)
    int widthOfBinaryTree(TreeNode* root) {
        if (NULL == root) return 0;
        queue<pair<TreeNode*, int>> Level;
        Level.emplace(root, 0);
        int ans = 0;
        while (!Level.empty()) {
            queue<pair<TreeNode*, int>> nextLevel;
            int l = INT_MAX, r = INT_MIN;
            while (!Level.empty()) {
                TreeNode *tmp = Level.front().first;
                int pos = Level.front().second;
                Level.pop();
                l = min(l, pos);
                r = max(r, pos);
                if (tmp->left) nextLevel.emplace(tmp->left, pos * 2);
                if (tmp->right) nextLevel.emplace(tmp->right, pos * 2 + 1);
            }
            Level = nextLevel;
            ans = max(ans, r - l + 1);
        }
        return ans;
    }
};
