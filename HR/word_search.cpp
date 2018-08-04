class Solution {
public:
    // Backtracking
    // Time O(3^m)  Space O(m)
    bool dfs(vector<vector<char>>& board, string& word, int x, int y, int pos) {
        bool ans = false;
        if (board[y][x] == word[pos]) {
            char tmp = board[y][x];
            board[y][x] = '#';
            if (pos == word.size() - 1) {
                ans = true;
            }
            if (!ans && y > 0) ans |= dfs(board, word, x, y-1, pos+1);
            if (!ans && x > 0) ans |= dfs(board, word, x-1, y, pos+1);
            if (!ans && y < board.size() - 1) ans |= dfs(board, word, x, y+1, pos+1);
            if (!ans && x < board[0].size() - 1) ans |= dfs(board, word, x+1, y, pos+1);
            board[y][x] = tmp;
        }
        return ans;
    }
    bool exist(vector<vector<char>>& board, string word) {
        int n = board.size();
        if (!n) return false;
        int m = board[0].size();
        for (int y = 0; y < n; y++) {
            for (int x = 0; x < m; x++) {
                if (dfs(board, word, x, y, 0)) return true;
            }
        }
        return false;
    }
};
