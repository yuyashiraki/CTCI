class Solution {
public:
    // Using two pointers; last 0 pointer and current pointer
    // Time O(n)  Space O(1)
    void moveZeroes(vector<int>& nums) {
        int n = nums.size(), last = 0, i;
        for (i = last; i < n; i++) {
            if (0 != nums[i]) {
                int tmp = nums[last];
                nums[last] = nums[i];
                nums[i] = tmp;
                last++;
            }
        }
    }

    // Bubble Sort
    // Time O(n^2)  Space O(1)
    void moveZeroes(vector<int>& nums) {
        int n = nums.size(), cur = n;
        for (int i = n - 1; i >= 0; i--) {
            if (0 == nums[i]) {
                for (int j = i; j < cur - 1; j++) {
                    int tmp = nums[j + 1];
                    nums[j + 1] = nums[j];
                    nums[j] = tmp;
                }
                cur--;
            }
        }
    }
};
