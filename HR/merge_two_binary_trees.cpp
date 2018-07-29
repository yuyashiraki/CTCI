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
    // Time O(n) Space O(log(n))
    TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2) {
        if (t1 && t2) {
            t1->val += t2->val;
            t1->right = mergeTrees(t1->right, t2->right);
            t1->left = mergeTrees(t1->left, t2->left);
            return t1;
        }
        if (t1 && !t2) {
            return t1;
        }
        if (!t1 && t2) {
            return t2;
        }
        return NULL;
    }

    // BFS
    // Time O(n)  Space O(n)
    TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2) {
        TreeNode *ans;
        queue<tuple<TreeNode**,TreeNode*, TreeNode*>> Que;
        Que.emplace(&ans, t1, t2);
        while (!Que.empty()) {
            cout << "New Node" << endl;
            TreeNode **tmp = get<0>(Que.front()), *tt1 = get<1>(Que.front()), *tt2 = get<2>(Que.front());
            Que.pop();
            if (tt1 && tt2) {
                cout << "\t" << tt1->val << " " << tt2->val << endl;
                *tmp = tt1;
                tt1->val += tt2->val;
                Que.emplace(&((*tmp)->left), tt1->left, tt2->left);
                Que.emplace(&((*tmp)->right), tt1->right, tt2->right);
            }
            else if (tt1 && !tt2) {
                cout << "\t" << tt1->val << endl;
                *tmp = tt1;
            }
            else if (!tt1 && tt2) {
                cout << "\t" << tt2->val << endl;
                *tmp = tt2;
            }
            else {
                cout << "NULL" << endl;
                *tmp = NULL;
            }
        }
        return ans;
    }
};
