class Solution {
public:
    bool solve(int i, int j, int idx, vector<vector<char>> &board, string &word) {
        if(idx == word.size())
            return true;
        if(i>=board.size() || j>=board[0].size() || j<0 || i<0 || board[i][j]=='#')
            return false;
        if(word[idx]!=board[i][j])
            return false;
        int row[4] = {-1,0,0,1};
        int col[4] = {0,-1,1,0};
        char temp = board[i][j];
        board[i][j] = '#';
        for(int f=0;f<4;f++) { //O(4^o)
            int newr = i + row[f];
            int newc = j + col[f];
            if(solve(newr,newc,idx+1,board,word))
                return true;
        }
        board[i][j] = temp;
        return false;
    }
    bool exist(vector<vector<char>>& board, string word) {
        int n = board.size(),m=board[0].size();
        for(int i=0;i<n;i++) { //O(n)
            for(int j=0;j<m;j++) { //O(m)
                if(board[i][j]==word[0] && solve(i,j,0,board,word))
                    return true;
            }
        }
        return false;
    }
};
// n = no of rows
// m = no of cols
// o = no of words
//Time complexity: O(n*m*4^o)
//Space complexity: O(o)