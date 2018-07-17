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
    // Binary Search + recursive
    // Time: O(n)  Space: O(log(n))
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (!root || (!p && !q)) return NULL;
        if (q && p->val > q->val) swap(p, q);
        if (p->val > root->val) {
            return lowestCommonAncestor(root->right, p, q);
        }
        if (q && q->val < root->val) {
            return lowestCommonAncestor(root->left, p, q);
        }
        TreeNode *l = lowestCommonAncestor(root->left, p, NULL);
        TreeNode *r = lowestCommonAncestor(root->right, q, NULL);
        if (p == root || q == root || (l && r)) {
            return root;
        } else if (l) {
            return l;
        } else if (r) {
            return r;
        } else {
            return NULL;
        }
    }


    // Recursive
    // Time: O(n)  Space: O(log(n))
    TreeNode* recur(TreeNode* root, TreeNode* p, TreeNode* q)
    {
        if (NULL == root) return NULL;
        //cout << "root:" << root->val << " " << root << " " << p << " " << q << endl;
        TreeNode *l, *r, *self = NULL, *ans;
        if (root == p || root == q) {
            self = root;
        }
        l = recur(root->left, p, q);
        r = recur(root->right, p, q);
        //cout << "l:" << l << " r:" << r << endl;
        if (self || (l && r)) {
            ans = root;
        } else if (l) {
            ans = l;
        } else if (r) {
            ans = r;
        } else {
            ans = NULL;
        }
        return ans;
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        return recur(root, p, q);
    }
};
