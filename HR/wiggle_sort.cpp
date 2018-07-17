class Solution {
public:
    // One Pass
    // Time O(n)  Space O(1)
    void wiggleSort(vector<int>& nums) {
        if (nums.size() < 2) return;
        for (int i = 0; i < nums.size() - 1; i++) {
            if (i % 2 == 0 && nums[i] > nums[i + 1]) {
                swap(nums[i], nums[i + 1]);
            }
            if (i % 2 == 1 && nums[i] < nums[i + 1]) {
                swap(nums[i], nums[i + 1]);
            }
        }
    }

    // Sort and Swap
    // Time O(nlog(n)) Space O(1)
    void wiggleSort(vector<int>& nums) {
        if (nums.size() < 2) return;
        sort(nums.begin(), nums.end());
        for (int i = 1; i < nums.size() - 1; i += 2) {
            swap(nums[i], nums[i + 1]);
        }
    }
};
