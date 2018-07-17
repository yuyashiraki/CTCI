class Solution {
public:
    // Using two pointer
    // Time: O(n^2)  Space: O(1)
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        int sum, bb = INT_MIN, ll, rr, l, r;
        for (int i = 0; i < nums.size(); i++) {
            if (bb == nums[i]) continue;
            bb = nums[i], l = i + 1, r = nums.size() - 1;
            while (l < r) {
                ll = nums[l], rr = nums[r], sum = bb + ll + rr;
                if (0 == sum) {
                    ans.push_back(vector<int>{bb,ll,rr});
                }
                if (0 <= sum) {
                    while (nums[r] == rr && r > 0) r--;
                }
                if (0 >= sum) {
                    while (nums[l] == ll && l < nums.size() - 1) l++;
                }
            }
        }
        return ans;
    }
};
