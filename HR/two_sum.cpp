class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int, int> mp;
        for (int i = 0; i < nums.size(); i++) {
            int t = target - nums[i];
            if (mp.count(nums[i])) {
                return vector<int>{mp[nums[i]], i};
            } else {
                mp[t] = i;
            }
        }
    }
};
