class Solution {
   public:
    bool isValidSudoku(vector<vector<char>>& board) {
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                int val = board[i][j];
                if (val == '.') continue;

                // check if value repeats in its row
                for (int col = 0; col < 9; col++) {
                    // when we get to the same element
                    if (j == col) continue;
                    if (val == board[i][col]) {
                        return false;
                    }
                }

                // check if value repeats in its col
                for (int row = 0; row < 9; row++) {
                    if (i == row) continue;
                    if (val == board[row][j]) {
                        return false;
                    }
                }

                // Check duplicate in 3x3 box
                int startRow = (i / 3) * 3;
                int startCol = (j / 3) * 3;

                for (int r = startRow; r < startRow + 3; r++) {
                    for (int c = startCol; c < startCol + 3; c++) {
                        // Skip the current cell
                        if (r == i && c == j) continue;

                        if (board[r][c] == val) {
                            return false;
                        }
                    }
                }
            }
        }
        return true;
    }
};
