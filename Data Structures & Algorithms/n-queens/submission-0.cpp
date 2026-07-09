class Solution {
private:
    bool canPlace(int row, int col, vector<string> &res, int n) {
        // first check vertically
        for(int i = row; i >= 0; i--) {
            if (res[i][col] == 'Q') return false;
        }

        // check for left diagonal
        int i = row;
        int j = col;
        while(i >= 0 && j >= 0) {
            if (res[i][j] == 'Q') return false;
            i--;
            j--;
        }

        i = row;
        j = col;
        while(i >= 0 && j < n) {
            if (res[i][j] == 'Q') return false;
            i--;
            j++;
        }
        return true;
    }

    void findQueenPositions(int row, int n, vector<vector<string>> &ans, vector<string> &res) {
        if (row == n) {
            ans.push_back(res);
            return;
        }

        // at this row we will try to place all the columns if possible
        for(int col = 0; col < n; col++) {
            if (canPlace(row, col, res, n)) {
                res[row][col] = 'Q';
                findQueenPositions(row+1, n, ans, res);
                res[row][col] = '.';
            }
        }
    }
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<string> res(n, string(n, '.'));
        findQueenPositions(0, n, ans, res);
        return ans;
    }
};
