class Solution {
public: bool safe(int row, int col, int n, vector<string>& board) {
        // Check vertical column up
        for (int i = 0; i < row; i++) {
            if (board[i][col] == 'Q') return false;
        }

        // Check upper-left diagonal
        int r = row;
        int c = col;
        while (r >= 0 && c >= 0) {
            if (board[r][c] == 'Q') return false;
            r--; c--;
        }

        // Check upper-right diagonal
        r = row;
        c = col;
        while (r >= 0 && c < n) {
            if (board[r][c] == 'Q') return false;
            r--; c++;
        }

        return true;
    }

    void solve(int row, int n, vector<string>& board, vector<vector<string>>& result) {
        if (row == n) {
            result.push_back(board);
            return;
        }

        // Try placing a queen in every column of the current row
        for (int col = 0; col < n; col++) {
            if (safe(row, col, n, board)) {
                board[row][col] = 'Q';
                solve(row + 1, n, board, result);
                board[row][col] = '.'; // Backtrack
            }
        }
    }

    int totalNQueens(int n) {
         vector<vector<string>> result;
        vector<string> board(n, string(n, '.'));
        solve(0, n, board, result);
        int ans=result.size();
        return ans;
    }
};