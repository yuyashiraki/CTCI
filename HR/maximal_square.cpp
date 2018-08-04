class Solution {
public:
    // DP[x] = min(DP[x], DP[x-1], prev) + 1
    // Time O(nm)  Space O(m)
    int maximalSquare(vector<vector<char>>& matrix) {
        int n = matrix.size();
        if (!n) return 0;
        int m = matrix[0].size(), prev = 0, tmp;
        vector<int> dp(m, 0); // bottom right down corner of rectangle, the length of the side of rectangle
        int ans = 0;
        for (int y = 0; y < n; y++) {
            for (int x = 0; x < m; x++) {
                if ('0' == matrix[y][x]) {
                    prev = dp[x];
                    dp[x] = 0;
                } else {
                    if (x == 0) {
                        prev = dp[x];
                        dp[x] = 1;
                    } else {
                        tmp = min(min(dp[x], dp[x - 1]), prev) + 1;
                        prev = dp[x];
                        dp[x] = tmp;
                    }
                    ans = max(ans, dp[x]);
                }
            }
        }
        return ans*ans;
    }


    // Brute Force
    // Time O(nm^2)  Space O(m)
    int maximalSquare(vector<vector<char>>& matrix) {
        int n = matrix.size();
        if (!n) return 0;
        int m = matrix[0].size();
        vector<int> height(m, 0);
        int ans = 0;
        for (int y = 0; y < n; y++) {
            for (int x = 0; x < m; x++) {
                if ('0' == matrix[y][x]) height[x] = 0;
                else {
                    height[x]++;
                    int min_height = height[x];
                    for (int p = x; p >= 0; p--) {
                        min_height = min(min_height, height[p]);
                        int hor = x - p + 1;
                        if (min_height >= hor) ans = max(ans, hor*hor);
                        else break;
                    }
                }
            }
        }
        return ans;
    }
};
