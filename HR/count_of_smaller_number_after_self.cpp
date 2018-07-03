class Solution {
public:
    // Brute Force
    // Time O(n^2)
    vector<int> countSmaller(vector<int>& nums) {
        int n = (int)nums.size();
        vector<int> rt(n, 0);
        for (int i = 0 ; i < n - 1; i++) {
            for (int j = i + 1; j < n; j++) {
                if (nums[j] < nums[i]) rt[i]++;
            }
        }
        return rt;
    }

    // BST based
    // Time avg. O(nlog(n)) worst. O(n^2)  Space O(n)
    class Node {
    public:
        Node *left, *right;
        int val, sum, dup;
        Node(int v) {
            val = v;
            sum = 0;
            dup = 1;
            left = NULL;
            right = NULL;
        }
    };
    vector<int> countSmaller(vector<int>& nums) {
        vector<int> ans(nums.size(), 0);
        Node *root = NULL;
        for (int i = nums.size() - 1; i >= 0; i--) {
            root = insert(nums[i], root, ans, i, 0);
        }
        return ans;
    }
    Node *insert(int num, Node *root, vector<int>& ans, int pos, int count) {
        Node *rt;
        if (!root) {
            rt = new Node(num);
            ans[pos] = count;
        } else {
            rt = root;
            if (num == rt->val) {
                rt->dup++;
                count += rt->sum;
                ans[pos] = count;
            } else if (num < rt->val) {
                rt->sum++;
                rt->left = insert(num, rt->left, ans, pos, count);
            } else { // num > rt->val
                count += rt->sum + rt->dup;
                rt->right = insert(num, rt->right, ans, pos, count);
            }
        }
        return rt;
    }

    // MergeSort based
};
