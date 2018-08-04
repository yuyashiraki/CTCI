class Solution {
public:
    // DP
    // Time O(mn) Space O(n)
    int uniquePaths(int m, int n) {
        vector<int> dp(n, 0);
        int x, y;
        for (y = 0; y < m; y++) {
            for (x = 0; x < n; x++) {
                if (0 == y) dp[x] = 1;
                else {
                    if (x > 0) dp[x] += dp[x-1];
                }
            }
        }
        return dp[n-1];
    }
};
