class Solution {
public:
    // DP(top down)
    // Time O(S*n) where S is the amount, n is the coins  Space O(S)
    int coinChange(vector<int>& coins, int amount) {
        queue<pair<int, int>> q;
        vector<int> dp(amount + 1, -1);
        dp[amount] = 0;
        for (int i = amount - 1; i >= 0; i--) {
            for (int coinidx = 0; coinidx < coins.size(); coinidx++) {
                if ((long long)i + coins[coinidx] > amount || -1 == dp[i + coins[coinidx]]) continue;
                if (-1 == dp[i]) {
                    dp[i] = dp[i + coins[coinidx]] + 1;
                } else {
                    dp[i] = min(dp[i], dp[i + coins[coinidx]] + 1);
                }
            }
        }
//        for (int i = amount; i >= 0; i--) {
//            cout << dp[i] << endl;
//        }
        return dp[0];
    }
};
