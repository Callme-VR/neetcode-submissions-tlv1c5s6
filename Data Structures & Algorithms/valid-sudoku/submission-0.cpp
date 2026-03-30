class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int rows[9] = {0};
        int cols[9] = {0};
        int squares[9] = {0};

        for (int r = 0; r < 9; ++r) {
            for (int c = 0; c < 9; ++c) {

                if (board[r][c] == '.') continue;

                int value = board[r][c] - '1';

                // check if already present
                if ((rows[r] & (1 << value)) ||
                    (cols[c] & (1 << value)) ||
                    (squares[(r / 3) * 3 + (c / 3)] & (1 << value))) {
                    return false;
                }

                // mark the value
                rows[r] |= (1 << value);
                cols[c] |= (1 << value);
                squares[(r / 3) * 3 + (c / 3)] |= (1 << value);
            }
        }
        return true;
    }
};
