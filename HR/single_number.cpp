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
};
