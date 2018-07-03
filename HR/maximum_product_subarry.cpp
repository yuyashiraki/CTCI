class Solution {
public:
    // Genius Answer
    // Time O(n)  Space O(1)
    int maxProduct(vector<int>& nums) {
        int r = nums[0];
        for (int i = 1; imax = r, imin = r; i < n; i++) {
            if (A[i] < 0) {
                swap(imax, imin);
            }
            imax = max(A[i], imax * A[i]);
            imin = min(A[i], imin * A[i]);

            r = max(r, imax);
        }
        return r;
    }

    // Wrong Answer
    // Approach is not bad I guess
    // Time O(N)  Space O(N)
    int maxProduct(vector<int>& nums) {
        if (!nums.size()) return 0;
        if (nums.size() == 1 && nums[0] == 0) return 0;
        vector<int> products{1};
        int rt = INT_MIN, n;
        set<int> neg_tree, pos_tree;
        pos_tree.insert(products[0]);
        for (int i = 0; i < nums.size(); i++) {
            if (!products[i]) {
                products.push_back(nums[i]);
            } else {
                products.push_back(products[i] * nums[i]);
            }
            if (!products[i + 1]) {
                if (!neg_tree.empty()) {
                    n = neg_tree.size();
                    int neg_min = *(neg_tree.begin());
                    if (n > 1) {
                        int neg_max = *(next(neg_tree.begin(), n - 1));
                        int tmp = neg_min / neg_max;
                        rt = max(rt, tmp);
                    } else {
                        rt = max(rt, 0);
                    }
                }
                if (!pos_tree.empty()) {
                    n = pos_tree.size();
                    int pos_min = *(pos_tree.begin());
                    if (n > 1) {
                        int pos_max = *(next(pos_tree.begin(), n - 1));
                        int tmp = pos_max / pos_min;
                        rt = max(rt, tmp);
                    }
                }
                /* reset */
                neg_tree.clear(); pos_tree.clear();
                pos_tree.insert(1);
            } else if (products[i + 1] < 0) {
                neg_tree.insert(products[i + 1]);
            } else { /* products[i] > 0 */
                pos_tree.insert(products[i + 1]);
            }
            cout << products[i + 1] << endl;
        }
        if (!neg_tree.empty()) {
            n = neg_tree.size();
            int neg_min = *(neg_tree.begin());
            if (n > 1) {
                int neg_max = *next(neg_tree.begin(), n - 1);
                int tmp = neg_min / neg_max;
                rt = max(rt, tmp);
            } else {
                rt = max(rt, neg_min);
            }
        }
        if (!pos_tree.empty()) {
            n = pos_tree.size();
            int pos_min = *(pos_tree.begin());
            if (n > 1) {
                int pos_max = *(next(pos_tree.begin(), n - 1));
                int tmp = pos_max / pos_min;
                rt = max(rt, tmp);
            }
        }
        return rt;
    }

};
