class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        if (nums.size() == 0) return 0;
        int ans = 1;
        int cur = 0, prev = INT_MIN;
        for (int i = 0; i < nums.size(); i++) {
            if (prev < nums[i]) {
                cur++;
                ans = max(ans, cur);
            } else {
                cur = 1;
            }
            prev = nums[i];
        }
        return ans;
    }
};
