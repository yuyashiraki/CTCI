class Solution {
public:
    int recur(vector<vector<int>>& grid, int x, int y)
    {
        if (grid[y][x] == 2) return 0;
        grid[y][x] = 2;
        int ans = 4;
        if (x > 0 && grid[y][x - 1] > 0) {
            ans--;
            ans += recur(grid, x - 1, y);
        }
        if (x + 1 < grid[0].size() && grid[y][x + 1] > 0) {
            ans--;
            ans += recur(grid, x + 1, y);
        }
        if (y > 0 && grid[y - 1][x] > 0) {
            ans--;
            ans += recur(grid, x, y -1);
        }
        if (y + 1 < grid.size() && grid[y + 1][x] > 0) {
            ans--;
            ans += recur(grid, x, y + 1);
        }
        return ans;
    }
    int islandPerimeter(vector<vector<int>>& grid) {
        bool flg = false;
        int x, y;
        for (y = 0; y < grid.size(); y++) {
            for (x = 0; x < grid[0].size(); x++) {
                if (1 == grid[y][x]) {
                    flg = true;
                    break;
                }
            }
            if (flg) break;
        }
        return recur(grid, x, y);
    }
};
