class Solution {
public:
    // DP
    // Time O(n)  Space O(1)
    bool canJump(vector<int>& nums) {
        int lastpos = nums.size() - 1;
        for (int i = lastpos - 1; i >= 0; i--) {
            if (lastpos - i <= nums[i]) lastpos = i;
        }
        return lastpos == 0;
    }
};
