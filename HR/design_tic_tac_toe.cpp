class TicTacToe {
private:
    // keep count for each row, column, and diagonal. if player 1, add 1, and if player 2, add -1 to the count so that if abs(count) == N, one of them beat another.
    int N;
    vector<int> rows;
    vector<int> cols;
    int diagonal, antidiagonal;
public:
    /** Initialize your data structure here. */
    TicTacToe(int n) {
        N = n;
        rows = vector<int>(n, 0);
        cols = vector<int>(n, 0);
        diagonal = 0;
        antidiagonal = 0;
    }

    /** Player {player} makes a move at ({row}, {col}).
        @param row The row of the board.
        @param col The column of the board.
        @param player The player, can be either 1 or 2.
        @return The current winning condition, can be either:
                0: No one wins.
                1: Player 1 wins.
                2: Player 2 wins. */
    int move(int row, int col, int player) {
        int inc = player == 2 ? -1 : 1;
        if (abs(rows[row] += inc) == N)
            return rows[row] < 0 ? 2 : 1;
        if (abs(cols[col] += inc) == N)
            return cols[col] < 0 ? 2 : 1;
        if (row == col && abs(diagonal += inc) == N)
            return diagonal < 0 ? 2 : 1;
        if (N - 1 - row == col && abs(antidiagonal += inc) == N)
            return antidiagonal < 0 ? 2 : 1;
        cout << rows[row] << " " << cols[col] << " " << diagonal << " " << antidiagonal << endl;
        return 0;
    }
};

/**
 * Your TicTacToe object will be instantiated and called as such:
 * TicTacToe obj = new TicTacToe(n);
 * int param_1 = obj.move(row,col,player);
 */
