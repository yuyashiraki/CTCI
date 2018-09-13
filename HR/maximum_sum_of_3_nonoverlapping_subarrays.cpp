class Solution {
public:
    // Greedy
    // Time O(3n)  Space O(n)
    vector<int> maxSumOfThreeSubarrays(vector<int>& nums, int k) {
        vector<int> ans(3);
        vector<pair<int,int>> left_max_subarray(nums.size());
        vector<pair<int,int>> right_max_subarray(nums.size());
        int sum = 0, i;
        pair<int, int> maxpair = make_pair(0,0);
        for (i = 0; i < nums.size(); i++) {
            if (i < k) {
                sum += nums[i];
                left_max_subarray[i] = make_pair(sum, 0);
                maxpair = left_max_subarray[i];
            } else {
                sum += nums[i];
                sum -= nums[i - k];
                if (sum > maxpair.first)
                    maxpair = make_pair(sum, i - k + 1);
                left_max_subarray[i] = maxpair;
            }
        }
        maxpair = make_pair(sum, nums.size() - k);
        for (i = nums.size() - 1; i >= 0; i--) {
            if (i >= nums.size() - k) {
                right_max_subarray[i] = make_pair(sum, nums.size() - k);
            } else {
                sum += nums[i];
                sum -= nums[i + k];
                if (sum >= maxpair.first)
                    maxpair = make_pair(sum, i);
                right_max_subarray[i] = maxpair;
            }
        }
        int middle = 0;
        for (i = k - 1; i < 2 * k - 1; i++) {
            middle += nums[i];
        }
        int maxsum = 0;
        for (i = k; i + k <= nums.size() - k; i++) {
            middle += nums[i + k - 1];
            middle -= nums[i - 1];
            sum = left_max_subarray[i - 1].first + middle + right_max_subarray[i + k].first;
            if (maxsum < sum) {
                ans[0] = left_max_subarray[i - 1].second;
                ans[1] = i;
                ans[2] = right_max_subarray[i + k].second;
                maxsum = sum;
            }
        }
        return ans;
    }
};
