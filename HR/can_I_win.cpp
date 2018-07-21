class Solution {
public:
    // DFS + Memoization
    // Time O(2^n)  Space O(2^n)
    unordered_map<int, bool> memo;
    bool canIWin(int maxChoosableInteger, int desiredTotal) {
        if (desiredTotal < 1) return true;
        int sum = maxChoosableInteger * (1 + maxChoosableInteger) / 2;
        if (sum < desiredTotal) return false;
        if (sum == desiredTotal) return maxChoosableInteger % 2;
        return dfs(maxChoosableInteger, desiredTotal, 0);
    }
    bool dfs(int maxChoosableInteger, int desiredTotal, int k) {
        if (desiredTotal <= 0) return false;
        if (memo.find(k) != memo.end()) return memo[k];
        memo[k] = false;
        for (int i = 1; i <= maxChoosableInteger; i++) {
            if (k & (1 << i)) continue;
            if (!dfs(maxChoosableInteger, desiredTotal - i, k | (1 << i))) {
                memo[k] = true;
                break;
            }
        }
        return memo[k];
    }
};
