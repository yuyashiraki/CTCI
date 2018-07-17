class Solution {
public:
    // One-pass without extra-memory
    // Time O(n^2)  Memory O(1)
    int countBattleships(vector<vector<char>>& board) {
        if (0 == board.size() || 0 == board[0].size()) return 0;
        int ans = 0;
        for (int y = 0; y < board.size(); y++) {
            for (int x = 0; x < board[0].size(); x++) {
                if (board[y][x] == 'X' && (y == 0 || board[y - 1][x] == '.') && (x == 0 || board[y][x - 1] == '.'))
                    ans++;
            }
        }
        return ans;
    }
};
