class Solution {
public:
    // DP
    // Time: O(n)  Space: O(1)
    int rob(vector<int>& nums) {
        int n = nums.size();
        int currMax = 0, prevMax = 0;
        for (int i = 0; i < n; i++) {
            int tmp = currMax;
            currMax = max(prevMax + nums[i], currMax);
            prevMax = tmp;
        }
        return currMax;
    }
};
