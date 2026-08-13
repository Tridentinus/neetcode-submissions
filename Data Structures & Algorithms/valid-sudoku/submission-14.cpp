class Solution {
    unordered_map<int, unordered_set<char>> rows;
    unordered_map<int, unordered_set<char>> cols;
    unordered_map<int, unordered_set<char>> sqrs;
public:

    int getSqr(int r, int c) {
        return 3*(r/3) + c/3;
    }
    bool isValidSudoku(vector<vector<char>>& board) {

        for (int r = 0; r < 9; r++) {
            for (int c = 0; c < 9; c++) {
                char symbol = board[r][c];
                if (symbol == '.') continue;
                int sqr = getSqr(r,c);
                if (rows[r].contains(symbol) || cols[c].contains(symbol) || sqrs[sqr].contains(symbol)) return false;

                rows[r].insert(symbol);
                cols[c].insert(symbol);
                sqrs[sqr].insert(symbol);
            }
        }

        return true;

    }
};
