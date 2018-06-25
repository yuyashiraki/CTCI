class Solution {
public:
    // Brute Force: Time O(N!) N factorial
    // Single Pass Approach: Time O(N)
    void nextPermutation(vector<int>& nums) {
        int prev = nums[nums.size() - 1];
        int i;
        for (i = nums.size() - 2; i >= 0; i--) {
            if (nums[i] < prev) {
                reverse(nums.begin() + i + 1, nums.end());
                iter_swap(upper_bound(nums.begin() + i + 1, nums.end(), nums[i]), nums.begin() + i);
                break;
            }
            prev = nums[i];
        }
        if (i < 0) reverse(nums.begin(), nums.end());
    }
};
