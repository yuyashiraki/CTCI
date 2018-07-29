class Solution {
public:
    // using 3 pointers
    // Time O(n) Space O(1)
    void sortColors(vector<int>& nums) {
        int pos0 = 0, pos2 = nums.size() - 1;
        while (pos0 < nums.size() - 1 && nums[pos0] == 0) pos0++;
        while (pos2 > 0 && nums[pos2] == 2) pos2--;
        int i = pos0;
        while (i < nums.size()) {
            if (i < pos0) {
                i = pos0;
                continue;
            }
            if (i > pos2) {
                break;
            }
            if (nums[i] == 0) {
                swap(nums[pos0++], nums[i]);
            } else if (nums[i] == 2) {
                swap(nums[pos2--], nums[i]);
            } else {
                i++;
                continue;
            }
        }
    }

    // Counting Sort
    // Time O(n) Space O(n)
    void sortColors(vector<int>& nums) {
        vector<int> counter(3, 0);
        for (int i = 0; i < nums.size(); i++) {
            counter[nums[i]]++;
        }
        int pos = 0;
        for (int i = 0; i < counter.size(); i++) {
            while (counter[i]--) {
                nums[pos++] = i;
            }
        }
    }

};
