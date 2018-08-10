class Solution {
public:
    // one pass + Binary Search
    // Time O(nlog(n))  Space O(n)
    int lengthOfLIS(vector<int>& nums) {
        int len = 0;
        for (int i = 0; i < nums.size(); i++) {
            auto itr = lower_bound(nums.begin(), nums.begin() + len, nums[i]);
            if (itr == nums.begin() + len) {
                nums[len] = nums[i];
                len++;
            } else {
                *itr = nums[i];
            }
        }
        return len;
    }


    // DP
    // Time O(n^2)  Space O(n)
    int lengthOfLIS(vector<int>& nums) {
        vector<int> dp(nums.size(), 1);
        int ans = 0;
        for (int i = 0; i < nums.size(); i++) {
            ans = max(ans, dp[i]);
            for (int j = i + 1; j < nums.size(); j++) {
                if (nums[j] <= nums[i]) continue;
                dp[j] = max(dp[i] + 1, dp[j]);
            }
        }
        return ans;
    }
};
