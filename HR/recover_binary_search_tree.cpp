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
    // Inorder Traversal
    // Time O(n)  Space O(1)
    TreeNode *prv = NULL, *swapfirst = NULL, *swapsecond = NULL;
    void rec(TreeNode *root) {
        if (NULL == root) return;
        if (root->left) {
            rec(root->left);
        }
        cout << "AT: " << root->val << endl;
        if (NULL != prv && prv->val > root->val) {
            if (NULL == swapfirst) {
                swapfirst = prv;
                swapsecond = root;
            } else {
                swapsecond = root;
            }
        }
        prv = root;
        if (prv) {
            cout << "PREV: " << prv->val << endl;
        }
        if (swapfirst) {
            cout << "FIRST: " << swapfirst->val << endl;
        }
        if (swapsecond) {
            cout << "SECOND: "<< swapsecond->val << endl;
        }
        if (root->right) {
            rec(root->right);
        }
    }
    void recoverTree(TreeNode* root) {
        rec(root);
        if (swapfirst && swapsecond) {
            swap(swapfirst->val, swapsecond->val);
        }
    }
};
