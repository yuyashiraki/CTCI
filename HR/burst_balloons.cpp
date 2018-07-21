class Solution {
public:
    // divide and conquer
    // Time O(n^3)  Space O(n^2)
    int maxCoins(vector<int>& nums) {
        vector<int> Nums(nums.size() + 2);
        int n = 1;
        for (auto x : nums) {
            if (x > 0) nums[n++] = x;
        }
        nums[0] = nums[n++] = 1;

        int memo[n][n] = {{0}};
        return burst(memo, nums, 0, n - 1);
    }
    int burst(int memo[][], int nums[], int left, int right) {
        if (left + 1 == right) return 0;
        if (memo[left][right] > 0) return memo[left][right];
        int ans = 0;
        for (int i = left + 1; i < right; ++i) {
            ans = max(ans, nums[left]*nums[i]*nums[right] + burst(memo, nums, left, i) + burst(memo, nums, i, right));
        }
        memo[left][right] = ans;
        return ans;
    }

    // dfs + memoization
    // Time < O(n!)  Space O(n)
    map<string, int> dp;
    int maxCoins(vector<int>& nums) {
        if (0 == nums.size()) return dp[""] = 0;
        string key = to_string(nums[0]);
        for (int i = 1; i < nums.size(); i++) {
            key += " " + to_string(nums[i]);
        }
        if (dp.count(key)) return dp[key];
        int ans = 0;
        for (int i = 0; i < nums.size(); i++) {
            vector<int> tmp = nums;
            int coins = nums[i];
            if (i > 0) coins *= nums[i - 1];
            if (i < nums.size() - 1) coins *= nums[i + 1];
            tmp.erase(tmp.begin() + i);
            coins += maxCoins(tmp);
            ans = max(ans, coins);
        }
        dp[key] = ans;
        return ans;
    }
};
