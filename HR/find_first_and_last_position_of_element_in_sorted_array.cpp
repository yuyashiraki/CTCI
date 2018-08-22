class Solution {
public:
    // Using binary search with different if condition
    // Time O(log(n))  Space O(1)
    int lbound(const vector<int>& nums, const int &target) {
        int l = 0, r = nums.size();
        while (l < r) {
            int mid = l + (r - l) / 2;
            if (nums[mid] < target) {
                l = mid + 1;
            } else {
                r = mid;
            }
        }
        return r;
    }
    int ubound(const vector<int>& nums, const int &target) {
        int l = 0, r = nums.size();
        while (l < r) {
            int mid = l + (r - l) / 2;
            if (nums[mid] <= target) {
                l = mid + 1;
            } else {
                r = mid;
            }
        }
        return r - 1;
    }
    vector<int> searchRange(vector<int>& nums, int target) {
        int l = lbound(nums,target), u = ubound(nums,target);
        if (l > u) return vector<int>{-1,-1};
        else return vector<int>{l,u};
    }
};
