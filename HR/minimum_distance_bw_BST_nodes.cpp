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
    // using Set for sorting O(NlogN)
    // using two pointers O(N)
    enum from {
        LEFT = 0, RIGHT = 1, INITIAL = 2,
    };
    int minDiffInBST(TreeNode* root, enum from fr_direction, int cmp, int parent)
    {
        //cout << "root:" << root->val << ", direction:"<< fr_direction << ", cmp:" << cmp << ", parent:" << parent << endl;
        int rt = INT_MAX;
        if (root->left) {
            enum from nxt_direction = LEFT;
            if (fr_direction == nxt_direction) {
                rt = min(rt, minDiffInBST(root->left, LEFT, cmp, root->val));
            } else {
                rt = min(rt, minDiffInBST(root->left, LEFT, parent, root->val));
            }
        }
        if (root->right) {
            enum from nxt_direction = RIGHT;
            if (fr_direction == nxt_direction) {
                rt = min(rt, minDiffInBST(root->right, RIGHT, cmp, root->val));
            } else {
                rt = min(rt, minDiffInBST(root->right, RIGHT, parent, root->val));
            }
        }
        rt = min((int)abs(parent - root->val), rt);
        rt = min((int)abs(cmp - root->val), rt);
        return rt;
    }
    int minDiffInBST2(TreeNode* root)
    {
        return minDiffInBST(root, INITIAL, INT_MAX, INT_MAX);
    }

    // In-order traversal O(N)
    int predecessor = -101;
    int ans = 201;
    int minDiffInBST(TreeNode *root)
    {
        if (!root) return ans;
        minDiffInBST(root->left);
        ans = min(ans, root->val - predecessor);
        predecessor = root->val;
        minDiffInBST(root->right);
        return ans;
    }
};
