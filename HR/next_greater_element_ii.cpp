class Solution {
public:
    // Two pass using Stack
    // Time: O(n)  Space O(n)
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n, -1);
        if (0 == n) return ans;
        stack<int> STK;
        int cnt = 0;
        for (int i = 0; i < n * 2; i++) {
            while (!STK.empty() && nums[STK.top()] < nums[i % n]) {
                ans[STK.top()] = nums[i % n];
                STK.pop();
            }
            if (ans[i] == -1) STK.push(i % n);
        }
        return ans;
    }
};
