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
    // Recursive
    // Time O(n) Space O(log(n))
    bool recur(TreeNode *left, TreeNode *right) {
        if (left && right && left->val == right->val) {
            return recur(left->right, right->left) && recur(left->left, right->right);
        }
        if (left == NULL && right == NULL) {
            return true;
        }
        return false;
    }
    bool isSymmetric(TreeNode* root) {
        if (root == NULL) return true;
        return recur(root->left, root->right);
    }

    // Iterative
    // Time O(n)  Space O(n)
    bool isSymmetric(TreeNode* root) {
        if (root == NULL) return true;
        queue<TreeNode *> leftnodes, rightnodes;
        leftnodes.push(root->left); rightnodes.push(root->right);
        while (!leftnodes.empty() && !rightnodes.empty()) {
            TreeNode *l = leftnodes.front();
            TreeNode *r = rightnodes.front();
            leftnodes.pop(); rightnodes.pop();
            if (l == NULL && r == NULL) {
                continue;
            }
            if (l && r && l->val == r->val) {
                leftnodes.push(l->left); leftnodes.push(l->right);
                rightnodes.push(r->right); rightnodes.push(r->left);
                continue;
            }
            return false;
        }
        if (leftnodes.empty() && rightnodes.empty()) {
            return true;
        } else {
            return false;
        }
    }};
