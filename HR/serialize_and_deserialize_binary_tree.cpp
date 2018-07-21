/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:
    // Using BFS + pointer pointer
    // Encodes a tree to a single string.
    // Time O(n)  Space O(n)
    string serialize(TreeNode* root) {
        string ans = "[";
        if (!root) {
            ans += "]";
            return ans;
        }
        queue<TreeNode*> Que;
        Que.push(root);
        while (!Que.empty()) {
            TreeNode *cur = Que.front(); Que.pop();
            if (cur) {
                if (cur == root) ans += to_string(cur->val);
                else ans += "," + to_string(cur->val);
                Que.push(cur->left);
                Que.push(cur->right);
            } else {
                ans += ",n";
            }
        }
        ans += "]";
        return ans;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        cout << data << endl;
        if (data.size() < 3) {
            return NULL;
        }
        data.erase(0, 1); data.erase(data.size() - 1, 1);  // remove "[]"
        TreeNode *root;
        istringstream ss(data);
        queue<TreeNode**> Que;
        Que.push(&root);
        string cur;
        while (getline(ss, cur, ',')) {
            TreeNode **p = Que.front(); Que.pop();
            if (cur == "n") {
                *p = NULL;
            } else {
                *p = new TreeNode(stoi(cur));
                Que.push(&((*p)->left)); Que.push(&((*p)->right));
            }
        }
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));
