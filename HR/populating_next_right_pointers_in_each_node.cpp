/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
class Solution {
public:
    // BFS
    // Time O(n)  Space O(1)
    void connect(TreeLinkNode *root) {
        TreeLinkNode *parent = root;
        while (parent) {
            TreeLinkNode *cur = parent;
            while (cur && cur->left) {
                cur->left->next = cur->right;
                if (cur->next) cur->right->next = cur->next->left;
                cur = cur->next;
            }
            parent = parent->left;
        }
    }
    // Time O(n)  Space O(n)
    void connect(TreeLinkNode *root) {
        queue<pair<TreeLinkNode*,int>> Q;
        TreeLinkNode *prev = NULL;
        int prev_lv = 0;
        Q.emplace(root,0);
        while (!Q.empty()) {
            TreeLinkNode *cur = Q.front().first;
            int level = Q.front().second;
            Q.pop();
            if (!cur) continue;
            if (prev) {
                if (prev_lv == level) {
                    prev->next = cur;
                } else {
                    prev->next = NULL;
                }
            }
            prev = cur;
            prev_lv = level;
            Q.emplace(cur->left, level + 1);
            Q.emplace(cur->right, level + 1);
        }
        if (prev) prev->next = NULL;
    }
};
