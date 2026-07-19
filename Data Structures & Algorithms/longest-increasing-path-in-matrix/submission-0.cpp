class Solution {
public:
    const int MOD = 1e9+7;
    int solve(int i, int j, vector<vector<int>>& matrix, vector<vector<int>> &dp) {
        if(dp[i][j]!=-1)
            return dp[i][j];
        int answer = 1;
        int row[4] = {-1,1,0,0};
        int col[4] = {0,0,-1,1};
        for(int ind=0;ind<4;ind++) {
            int newr = i+row[ind];
            int newc = j+col[ind];
            if(newr>=0 && newc>=0 && newr<matrix.size() && newc<matrix[0].size()) {
                if(matrix[newr][newc]>matrix[i][j])
                    answer = max(answer,(1+solve(newr,newc,matrix,dp))%MOD);
            }
        } 
        return dp[i][j] = answer;
    }
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int n = matrix.size(),m=matrix[0].size(),res=0;
        vector<vector<int>> dp(n,vector<int>(m,-1));
        for(int i=0;i<n;i++) {
            for(int j=0;j<m;j++) {
                res = max(res,solve(i,j,matrix,dp));
            }
        }
        return res;
    }
};
//Time complexity: O(n*m*4)
//Space complexity: O(n*m*4)