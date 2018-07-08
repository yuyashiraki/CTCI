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

    // Time O(N)  Space O(N)
    int maxProduct(vector<int>& nums) {
        if (!nums.size()) return 0;
        if (nums.size() == 1) return nums[0];
        vector<long long> products;
        int n = nums.size();
        long long ans = INT_MIN, neg_min;
        for (int i = 0; i < n; i++) {
            if (0 == i || 0 == products[i - 1]) {
                products.push_back(nums[i]);
                neg_min = INT_MIN;
            } else {
                products.push_back(products[i - 1] * nums[i]);
            }
            ans = max(ans, products[i]);
            if (products[i] < 0) {
                if (INT_MIN != neg_min) {
                    ans = max(ans, products[i] / neg_min);
                }
                neg_min = max(neg_min, products[i]);
            }
        }
        return (int) ans;
    }
};
