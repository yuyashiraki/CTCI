class Solution {
public:
    // Marking
    // Time O(2n)  Space O(1)
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        int i;
        vector<int> ans;
        for (i = 0; i < nums.size(); i++) {
            int val = abs(nums[i]) - 1;
            if (nums[val] > 0) {
                nums[val] = -nums[val];
            }
        }
        for (i = 0; i < nums.size(); i++) {
            if (nums[i] > 0) {
                ans.push_back(i + 1);
            }
        }
        return ans;
    }
};
