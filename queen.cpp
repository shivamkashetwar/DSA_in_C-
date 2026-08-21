class Solution {
public:
    bool issafe(vector<string>& board, int row, int col, int n) {

        // Check row
        for (int j = 0; j < n; j++) {
            if (board[row][j] == 'Q') {
                return false;
            }
        }

        // Check column
        for (int i = 0; i < n; i++) {
            if (board[i][col] == 'Q') {
                return false;
            }
        }

        // Check upper-left diagonal
        for (int i = row, j = col; i >= 0 && j >= 0; i--, j--) {
            if (board[i][j] == 'Q') {
                return false;
            }
        }

        // Check upper-right diagonal
        for (int i = row, j = col; i >= 0 && j < n; i--, j++) {
            if (board[i][j] == 'Q') {
                return false;
            }
        }

        return true;
    }

    void queen(vector<string>& board, int row, int n,
               vector<vector<string>>& ans) {

        // All queens placed
        if (row == n) {
            ans.push_back(board);
            return;
        }

        for (int j = 0; j < n; j++) {

            if (issafe(board, row, j, n)) {

                board[row][j] = 'Q';

                queen(board, row + 1, n, ans);

                // Backtracking
                board[row][j] = '.';
            }
        }
    }

    vector<vector<string>> solveNQueens(int n) {

        vector<string> board(n, string(n, '.'));
        vector<vector<string>> ans;

        queen(board, 0, n, ans);

        return ans;
    }
};