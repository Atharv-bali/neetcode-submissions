class Solution {
public:

    bool isValid(int row, int col, vector<vector<char>>& board, char d) {
        for(int i=0;i<9;i++) {//O(9)
            if(board[row][i]==d)
                return false;
            if(board[i][col]==d)
                return false;
        }
        int start_i = row/3 * 3;
        int start_j = col/3 * 3;
        for(int i=0;i<3;i++) { //O(3)
            for(int j=0;j<3;j++) { //O(3)
                if(board[start_i+i][start_j+j]==d)
                    return false;
            }
        }
        return true;
    }

    bool solve(vector<vector<char>>& board) {
        for(int i=0;i<9;i++) { //O(9)
            for(int j=0;j<9;j++) { // O(9)
                if(board[i][j]=='.')
                    continue;
                else {
                    char c = board[i][j];
                    board[i][j]='.';
                    if(isValid(i,j,board,c)==false) {
                        return false;
                    }
                    board[i][j]=c;
                }
            }
        }
        return true;
    }
    bool isValidSudoku(vector<vector<char>>& board) {
        return solve(board);
    }
};

// Time complexity: O(1)
