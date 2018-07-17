class Solution {
public:
    // cyclic rotation
    // Time O(n^2) for nxn matrix  Space O(1)
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        if (0 == n) return;
        for (int x = 0, y = 0; x < n/2; x++, y++) {
            int p, e = n - 1 - 2 * x;
            for (p = 0; p < e; p++) {
                int tmp = matrix[y][x + p];
                matrix[y][x + p] = matrix[n - 1 - y - p][x];
                matrix[n - 1 - y - p][x] = matrix[n - 1 - y][n - 1 - x - p];
                matrix[n - 1 - y][n - 1 - x - p] = matrix[y + p][n - 1 - x];
                matrix[y + p][n - 1 - x] = tmp;
            }
        }
    }
};
