class Solution {
   public:
    int row;
    int col;
    bool rec(vector<vector<char>>& board, string word, int i, int j, vector<vector<bool>> visited,
             int search) {
        if (board[i][j] != word[search]) return false;

        if (search == word.size() - 1) return true;

        visited[i][j] = true;
        bool top = false;
        bool down = false;
        bool left = false;
        bool right = false;
        // checking for top
        if (i - 1 >= 0 && visited[i - 1][j] == 0) {
            top = rec(board, word, i - 1, j, visited, search + 1);
        }
        if (i + 1 < row && visited[i + 1][j] == 0) {
            // checking for below
            down = rec(board, word, i + 1, j, visited, search + 1);
        }
        if (j - 1 >= 0 && visited[i][j - 1] == 0) {
            // checking for left
            left = rec(board, word, i, j - 1, visited, search + 1);
        }
        if (j + 1 < col && visited[i][j + 1] == 0) {
            // checking for right
            right = rec(board, word, i, j + 1, visited, search + 1);
        }

        return top || down || left || right;
    }
    bool exist(vector<vector<char>>& board, string word) {
        row = board.size();
        col = board[0].size();
        vector<vector<bool>> visited(row, vector<bool>(col, 0));
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                if (board[i][j] == word[0] && rec(board, word, i, j, visited, 0)) return true;
            }
        }
        return false;
    }
};
