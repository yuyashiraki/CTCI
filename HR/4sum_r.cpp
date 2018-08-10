class Solution {
public:
    // using 2sum
    // Time O(n^3)  Space O(1)
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> res;
        int len = nums.size();
        if (0 == len || len < 4) return res;
        sort(nums.begin(), nums.end());
        int max = nums[len - 1];
        if (4 * nums[0] > target || 4 * max < target) return res;
        int i, j, z;
        for (i = 0; i < len - 3; i++) {
            z = nums[i];
            if (nums[i]+nums[i+1]+nums[i+2]+nums[i+3] > target) break;
            if (nums[i]+nums[len-1]+nums[len-2]+nums[len-3] < target) continue;
            if (i > 0 && nums[i] == nums[i-1]) continue;
            for (j = i + 1; j < len - 2; j++) {
                if (nums[i]+nums[j]+nums[j+1]+nums[j+2] > target) break;
                if (nums[i]+nums[j]+nums[len-1]+nums[len-2] < target) continue;
                if (j > i + 1 && nums[j] == nums[j-1]) continue;
                int low = j + 1, high = len - 1;
                while (low < high) {
                    int sum = nums[i]+nums[j]+nums[low]+nums[high];
                    if (sum == target) {
                        res.push_back(vector<int>{nums[i],nums[j],nums[low],nums[high]});
                        while (low < high && nums[low]==nums[low+1])low++;
                        while (low < high && nums[high]==nums[high-1])high--;
                        low++;
                        high--;
                    } else if (sum < target) low++;
                    else high--;
                }
            }
        }
        return res;
    }

};
