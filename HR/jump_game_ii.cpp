class Solution {
public:
    // Level by level BFS
    // Time O(n)  Space O(1)
    int jump(vector<int>& nums) {
        if (nums.size() < 2) return 0;
        int cur = 0, next = 0, level = 0;
        while (next >= cur) {
            //cout << cur << " " << next << endl;
            level++;
            int nextnext = next;
            for (; cur <= next; cur++) {
                nextnext = max(nextnext, nums[cur] + cur);
                if (nextnext >= nums.size() - 1) return level;
            }
            next = nextnext;
        }
        return 0; // error
    }

    // DP (time limit exceeds)
    // Time O(n*m)  Space O(n)
    int jump(vector<int>& nums) {
        vector<int> DP(nums.size(), 0);
        for (int i = 0; i < nums.size(); i++) {
            if (0 == DP[i] && i > 0) continue;
            for (int j = 1; j <= nums[i] && i + j < nums.size(); j++) {
                DP[i + j] = DP[i + j] == 0 ? DP[i] + 1 : min(DP[i + j], DP[i] + 1);
            }
        }
        return DP[nums.size() - 1];
    }
};
