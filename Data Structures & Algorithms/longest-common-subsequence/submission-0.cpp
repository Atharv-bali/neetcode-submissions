class Solution {
public:
    int solve(int i, int j, string &text1, string &text2, vector<vector<int>> &dp) {
        if(i<=0 || j<=0)
            return 0;
        if(dp[i][j]!=-1)
            return dp[i][j];
        if(text1[i-1]==text2[j-1])
            return 1+solve(i-1,j-1,text1,text2,dp);
        int move_i = solve(i-1,j,text1,text2,dp);
        int move_j = solve(i,j-1,text1,text2,dp);
        return dp[i][j] = max(move_i,move_j);
    }
    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.size(), m = text2.size();
        vector<vector<int>> dp(n+1,vector<int>(m+1,-1));
        return solve(n,m,text1,text2,dp);
    }
};
//Time complexity: O(n*m)
//Space complexity: O(n*m)