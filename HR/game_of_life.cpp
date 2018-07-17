class Solution {
public:
    // Using marking
    // Time O(2mn)  Space O(1)
    void gameOfLife(vector<vector<int>>& board) {
        vector<vector<int>> directions = {{1,1},{-1,-1},{1,0},{0,1},{-1,0},{0,-1},{1,-1},{-1,1}};
        int n = board.size();
        if (0 == n) return;
        int m = board[0].size();
        if (0 == m) return;
        int x, y, dr;
        for (y = 0; y < n; y++) {
            for (x = 0; x < m; x++) {
                int neighborcnt = 0;
                for (dr = 0; dr < 8; dr++) {
                    int tx = x + directions[dr][0], ty = y + directions[dr][1];
                    if (tx < 0 || tx >= m || ty < 0 || ty >= n) continue;
                    if (board[ty][tx] % 10) neighborcnt++;
                }
                if (neighborcnt < 2 || neighborcnt > 3) {
                    board[y][x] += 0 * 10;
                } else if (neighborcnt == 3) {
                    board[y][x] += 10;
                } else { // if neighborcnt == 2
                    board[y][x] += board[y][x] * 10;
                }
            }
        }
        for (y = 0; y < n; y++) {
            for (x = 0; x < m; x++) {
                board[y][x] /= 10;
            }
        }
    }
};
