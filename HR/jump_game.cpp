class Solution {
public:
    // bottom-up DP: Time O(n^2)  Memory O(n)
    bool canJump(vector<int>& nums) {
        vector<bool> dp(nums.size(), false);
        dp[0] = true;
        for (int i = 0; i < nums.size(); i++) {
            if (dp[i] == false) continue;
            for (int j = 1; j <= nums[i]; j++) {
                dp[i + j] = true;
            }
        }
        return dp[nums.size() - 1];
    }

    // Greedy top-down: Time O(n)  Memory O(1)
    bool canJump(vector<int>& nums) {
        int lastpos = nums.size() - 1;
        for (int i = lastpos - 1; i >= 0; i--) {
            if (lastpos - i <= nums[i]) {
                lastpos = i;
            }
        }
        return lastpos == 0;
    }
};
