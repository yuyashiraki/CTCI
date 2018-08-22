class Solution {
public:
    // DP
    // Time O(nm)  Space O(m)
    int minPathSum(vector<vector<int>>& grid) {
        int n = grid.size();
        if (n == 0) return 0;
        int m = grid[0].size();
        vector<int> DP(m, 0);
        for (int y = 0; y < n; y++) {
            for (int x = 0; x < m; x++) {
                if (y == 0 && x == 0) {
                    DP[x] = grid[y][x];
                } else if (y == 0) {
                    DP[x] = DP[x - 1] + grid[y][x];
                } else if (x == 0) {
                    DP[x] += grid[y][x];
                } else {
                    DP[x] = min(DP[x - 1], DP[x]) + grid[y][x];
                }
            }
        }
        return DP[m - 1];
    }
};
