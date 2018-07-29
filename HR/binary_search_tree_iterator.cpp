/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class BSTIterator {
public:
    stack<TreeNode*> STK;
    BSTIterator(TreeNode *root) {
        TreeNode *cur = root;
        while (cur) {
            STK.push(cur);
            cur = cur->left;
        }
        cout << "Initialized" <<  endl;
    }

    /** @return whether we have a next smallest number */
    bool hasNext() {
        //cout << "size:" << STK.size() << endl;
        return !STK.empty();
    }

    /** @return the next smallest number */
    int next() {
        TreeNode *cur = STK.top();
        int ans = cur->val;
        STK.pop();
        cur = cur->right;
        while (cur) {
            STK.push(cur);
            cur = cur->left;
        }
        return ans;
    }
};

/**
 * Your BSTIterator will be called like this:
 * BSTIterator i = BSTIterator(root);
 * while (i.hasNext()) cout << i.next();
 */
