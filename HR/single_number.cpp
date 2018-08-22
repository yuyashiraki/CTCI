class Solution {
public:
    // using XOR
    // Time O(n)  Space O(1)
    int singleNumber(vector<int>& nums) {
        int x = 0;
        for (int i = 0; i < nums.size(); i++) {
            x ^= nums[i];
        }
        return x;
    }

    // Using Set
    // Time O(n)  Space O(n)
    int singleNumber(vector<int>& nums) {
        set<int> St;
        for (int i = 0; i < nums.size(); i++) {
            auto itr = St.find(nums[i]);
            if (itr != St.end()) St.erase(itr);
            else St.insert(nums[i]);
        }
        return *(St.begin());
    }

    // If sorted, check with previous number
    // Time O(n)  Space O(1)
    int singleNumber(vector<int>& nums) {
        int prev = 0, i;
        bool flg = true;
        for (i = 0; i < nums.size(); i++) {
            if (flg) prev = nums[i];
            else if (nums[i] != prev) return prev;
            flg = !flg;
        }
        return nums[i - 1];
    }
};
