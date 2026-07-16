class Solution {
public:
    bool isSafe(int n, int row, int col, vector<string> &board) {
        for(int i=0;i<row;i++) {
            if(board[i][col]=='Q')
                return false;
        }
        int i=row-1,j=col+1;
        while(i>=0 && j<n) {
            if(board[i][j]=='Q')
                return false;
            i--;
            j++;
        }
        i=row-1,j=col-1;
        while(i>=0 && j>=0) {
            if(board[i][j]=='Q')
                return false;
            i--;
            j--;
        }
        return true;
    }
    void nqueens(vector<string> &board, int row, int n, vector<vector<string>> &res) {
        if(row==n) {
            res.push_back(board);
            return;
        }
        for(int j=0;j<n;j++) {//O(n)
            if(isSafe(n,row,j,board)) {
                board[row][j] = 'Q';
                nqueens(board,row+1,n,res); // O(n)
                board[row][j] = '.';
            }
        }
    }

    vector<vector<string>> solveNQueens(int n) {
        vector<string> board(n,string(n,'.'));
        vector<vector<string>> res;
        nqueens(board,0,n,res);
        return res;
    }
};
//Time complexity: O(n^n) ~ O(n!)
//Space complexity: O(n^2)