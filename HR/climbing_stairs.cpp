class Solution {
public:
    // DP
    // Time: O(n)  Space: O(n)
    int climbStairs(int n) {
        /* you can only climb 1 or 2 steps each time. */
        if (n < 3) return n;
        int dp[n + 1] = {0, 1, 2};
        for (int i = 3; i <= n; i++) {
            dp[i] = dp[i - 1] + dp[i - 2];
        }
        return dp[n];
    }

    // Brute Force
    // Time: O(2^n)  Space: O(n)
    int climbStairs(int n) {
        return climbStairs(0, n);
    }
    int climbStairs(int i, int n) {
        if (i > n) {
            return 0;
        }
        if (i == n) {
            return 1;
        }
        return climbStairs(i + 1, n) + climbStairs(i + 2, n);
    }
};
