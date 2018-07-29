class Solution {
public:
    // two pointers find starting of the loop
    // Time O(n)  Space O(1)
    int findDuplicate(vector<int>& nums) {
        int hare = 0, turtoise = 0, n = nums.size();
        do {
            turtoise = nums[turtoise];
            hare = nums[nums[hare]];
        } while (hare != turtoise);
        hare = 0;
        while (hare != turtoise) {
            turtoise = nums[turtoise];
            hare = nums[hare];
        }
        return hare;
    }
};
