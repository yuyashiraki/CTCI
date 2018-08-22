class NumMatrix {
public:
    // using 2D cumulative sum
    // Time initial O(nm), O(1) per query
    // Space O(nm)
    vector<vector<int>> DP;
    NumMatrix(vector<vector<int>> matrix) {
        int n = matrix.size();
        if (n > 0) {
            int m = matrix[0].size();
            DP = matrix;
            for (int y = 0; y < n; y++) {
                for (int x = 0; x < m; x++) {
                    if (x > 0) DP[y][x] += DP[y][x - 1];
                    if (y > 0) DP[y][x] += DP[y - 1][x];
                    if (x > 0 && y > 0) DP[y][x] -= DP[y - 1][x - 1];
                    //cout << " " << DP[y][x];
                }
                //cout << endl;
            }
        } else {
            cout << "ERROR: Invalid matrix" << endl;
        }
    }

    int sumRegion(int row1, int col1, int row2, int col2) {
        //cout << row1 << " " << col1 << " " << row2 << " " << col2 << endl;
        int ans = DP[row2][col2];
        if (row1 > 0) ans -= DP[row1 - 1][col2];
        if (col1 > 0) ans -= DP[row2][col1 - 1];
        if (row1 > 0 && col1 > 0) ans += DP[row1 - 1][col1 - 1];
        //cout << ans << endl;
        return ans;
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix obj = new NumMatrix(matrix);
 * int param_1 = obj.sumRegion(row1,col1,row2,col2);
 */
