class Solution {
private:
    bool wordSearch(vector<vector<char>>& board, string word, int row, int col, int index) {
        if (index == word.size()) return true;

        if (row < 0 || row >= board.size() || col < 0 || col >= board[0].size() || board[row][col] != word[index]) {
            return false;
        }
        // Now we have 4 direction to move forward and mark current box as used
        char temp = board[row][col];
        board[row][col] = '1';
        bool isFound = wordSearch(board, word, row-1, col, index+1) || wordSearch(board, word, row+1, col, index+1) 
            || wordSearch(board, word, row, col-1, index+1) || wordSearch(board, word, row, col+1, index+1);
        board[row][col] = temp;
        return isFound;
    }
public:
    bool exist(vector<vector<char>>& board, string word) {
        for(int i = 0; i < board.size(); i++) {
            for(int j = 0; j < board[0].size(); j++) {
                if (board[i][j] == word[0]) {
                    if (wordSearch(board, word, i, j, 0)) {
                        return true;
                    }
                }
            }
        }
        return false;
    }
};
