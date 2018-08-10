class Solution {
public:
    // One pass
    // Time O(n)  Space O(1)
    void moveZeroes(vector<int>& nums) {
        int last = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (0 == nums[i]) continue;
            else {
                swap(nums[i], nums[last++]);
            }
        }
    }

    // Bubble sort like
    // Time O(n^2)  Space O(1)
    void moveZeroes(vector<int>& nums) {
        int cur = nums.size();
        for (int i = nums.size() - 1; i >= 0; i--) {
            if (nums[i] == 0) {
                for (int j = i; j < cur - 1; j++) {
                    swap(nums[j], nums[j+1]);
                }
                cur--;
            }
        }
    }
};
