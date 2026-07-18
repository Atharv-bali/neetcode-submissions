class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.size(), m = text2.size();
        // vector<vector<int>> dp(n+1,vector<int>(m+1,-1));
        vector<vector<int>> dp(n+1,vector<int>(m+1,0));
        for(int i=1;i<=n;i++) {
            for(int j=1;j<=m;j++) {
                if(text1[i-1]==text2[j-1])
                    dp[i][j] = 1+dp[i-1][j-1];
                else {
                    int move_i = dp[i-1][j];
                    int move_j = dp[i][j-1];
                    dp[i][j] = max(move_i,move_j);
                }
            }
        }
        return dp[n][m];
    }
};
//Time complexity: O(n*m)
//Space complexity: O(n*m)