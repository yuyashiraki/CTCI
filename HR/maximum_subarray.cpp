class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        long long n = nums.size(), ans = INT_MIN, minimum = 0, sum = 0;
        for (int i = 0; i < n; i++) {
            sum += (long long) nums[i];
            ans = max(ans, sum - minimum);
            minimum = min(minimum, sum);
        }
        return (int)ans;
    }
};
