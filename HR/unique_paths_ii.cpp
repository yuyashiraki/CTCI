class Solution {
public:
    // bottom-up DP
    // Time O(nm)  Space O(m)
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m, n;
        if (0 == (n = obstacleGrid.size())) return 0;
        m = obstacleGrid[0].size();
        vector<int> DP(m);
        DP[0] = 1;
        for (int y = 0; y < n; y++) {
            for (int x = 0; x < m; x++) {
                if (obstacleGrid[y][x] == 1) DP[x] = 0;
                else {
                    if (x > 0) DP[x] += DP[x - 1];
                }
            }
        }
        return DP[m - 1];
    }
};
