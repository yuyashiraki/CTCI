class Solution {
public:
    // Upperbound function
    int nextNumPos(vector<int>& nums, int x, int l, int r) {
        while (l <= r) {
            int md = (l+r)/2;
            if (x < nums[md]) {
                r = md - 1;
            } else {
                l = md + 1;
            }
        }
        while (nums[l] <= x) l++;
        return l;
    }
    // Reverse function
    void reverseVec(vector<int>& nums, int l, int r) {
        while (l < r) swap(nums[l++], nums[r--]);
    }
    void nextPermutation(vector<int>& nums) {
        int i, prev = nums[nums.size() - 1];
        for (i = nums.size() - 2; i >= 0; i--) {
            if (prev > nums[i]) {
                int l = i + 1, r = nums.size() - 1;
                reverseVec(nums, l, r);
                int pos = nextNumPos(nums, nums[i], l, r);
                //cout << pos << endl;
                swap(nums[i], nums[pos]);
                break;
            }
            prev = nums[i];
        }
        if (i < 0) {
            int l = 0, r = nums.size() - 1;
            reverseVec(nums, l, r);
        }
    }
};
