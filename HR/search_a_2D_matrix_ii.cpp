class Solution {
public:
    // BST
    // Time O(n+m)  Space O(1)
    bool searchMatrix(vector<vector<int>>& matrix, int target)
    {
        if (!matrix.size()) return false;
        int x = matrix[0].size() - 1, y = 0;
        while (x >= 0 && y < matrix.size()) {
            if (matrix[y][x] > target) {
                x--;
            } else if (matrix[y][x] < target) {
                y++;
            } else {
                return true;
            }
        }
        return false;
    }

    // binary search at on each row
    // Time O(nlogm)  Space O(1)
    bool searchMatrix(vector<vector<int>>& matrix, int target)
    {
        int i, n = matrix.size();
        if (!n) return false;
        int m = matrix[0].size();
        for (i = 0; i < n; i++) {
            if (binary_search(matrix[i].begin(), matrix[i].end(), target)) {
                return true;
            } else {
                continue;
            }
        }
        return false;
    }
};
