class Solution {
   public:
    bool func(int i, int j, vector<vector<char>>& board, string word, vector<vector<bool>>& vis) {
        vis[i][j] = 1;
        word.pop_back();

        if (word.empty()) return true;

        bool c1 = false, c2 = false, c3 = false, c4 = false;

        if (i - 1 >= 0 && !vis[i - 1][j] && board[i - 1][j] == word.back()) {
            c1 = func(i - 1, j, board, word, vis);
        }
        if (j - 1 >= 0 && !vis[i][j - 1] && board[i][j - 1] == word.back()) {
            c2 = func(i, j - 1, board, word, vis);
        }
        if (i + 1 < board.size() && !vis[i + 1][j] && board[i + 1][j] == word.back()) {
            c3 = func(i + 1, j, board, word, vis);
        }
        if (j + 1 < board[0].size() && !vis[i][j + 1] && board[i][j + 1] == word.back()) {
            c4 = func(i, j + 1, board, word, vis);
        }

        word.push_back(board[i][j]);
        vis[i][j] = 0;

        return c1 || c2 || c3 || c4;
    }

    bool exist(vector<vector<char>>& board, string word) {
        vector<vector<bool>> vis(board.size(), vector<bool>(board[0].size(), 0));

        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[0].size(); j++) {
                if (board[i][j] == word.back() && func(i, j, board, word, vis)) return true;
            }
        }

        return false;
    }
};