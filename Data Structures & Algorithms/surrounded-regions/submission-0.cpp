class Solution {
public:
    int row[4] = {-1,0,0,1};
    int col[4] = {0,-1,1,0};
    void dfs(vector<vector<char>>& board, int i, int j, vector<vector<int>> &vis) {
        if(board[i][j] == 'X')
            return;
        vis[i][j]=1;
        for(int ind=0;ind<4;ind++) {
            int newr = i+row[ind];
            int newc = j+col[ind];
            if(newr<0 || newc<0 || newr>=board.size() || newc>=board[0].size() || vis[newr][newc])
                continue;
            dfs(board,newr,newc,vis);
        }    
    }
    void solve(vector<vector<char>>& board) {
        int n = board.size(), m = board[0].size();
        vector<vector<int>>vis(n,vector<int>(m,0));
        for(int j=0;j<m;j++) { //O(m)
            dfs(board,0,j,vis); //O(n)
            dfs(board,n-1,j,vis);
        }
        for(int i=0;i<n;i++) {
            dfs(board,i,0,vis);
            dfs(board,i,m-1,vis);
        }
        for(int i=0;i<n;i++) {
            for(int j=0;j<m;j++) {
                if(!vis[i][j] && board[i][j]=='O')
                    board[i][j] = 'X';
            }
        }
        return;
    }
};
//Time complexity: O(m*n)
//Space complexity: O(m*n)