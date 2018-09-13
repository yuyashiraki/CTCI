class Solution {
public:
    // two pointer
    // Time O(n)  Space O(1)
    int minSubArrayLen(int s, vector<int>& nums) {
        int sum = 0, ans = INT_MAX;
        for (int l = 0, r = 0; r < nums.size(); r++) {
            sum += nums[r];
            while (l <= r && sum >= s) {
                ans = min(ans, r - l + 1);
                sum -= nums[l++];
            }
        }
        return ans == INT_MAX ? 0 : ans;
    }

    // binary search
    // Time O(nlog(n))  Space O(n)
    int minSubArrayLen(int s, vector<int>& nums) {
        vector<int> p(nums.size() + 1, 0);
        for (int i = 1; i < p.size(); i++) {
            p[i] = p[i - 1] + nums[i - 1];
        }
        int ans = INT_MAX;
        for (auto itr = p.begin(); itr != p.end(); ++itr) {
            auto nitr = lower_bound(itr + 1, p.end(), *itr + s);
            if (nitr == p.end()) break;
            int distance = nitr - itr;
            ans = min(ans, distance);
        }
        return ans == INT_MAX ? 0 : ans;
    }
};
