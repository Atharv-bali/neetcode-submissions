class Solution {
public:
    int uniquePaths(int m, int n) {
        // vector<vector<int>> dp(m+1,vector<int>(n+1,-1));
        vector<vector<int>> dp(m+1,vector<int>(n+1,0));
        dp[1][1] = 1;
        for(int i=1;i<=m;i++) {
            for(int j=1;j<=n;j++) {
                if(i==1 && j==1)
                    continue;
                int left = dp[i-1][j];
                int right = dp[i][j-1];
                dp[i][j] = left+right;
            }
        }
        return dp[m][n];
    }
};
//Time complexity: O(n*m)
//Space complexity: O(m*n)