class Solution {
public:
    int numDistinct(string s, string t) {
        int n = s.size(), m = t.size();
        // vector<vector<int>> dp(n+1,vector<int>(m+1,-1));
        vector<vector<int>> dp(n+1,vector<int>(m+1,0));
        for(int i=0;i<=n;i++)
            dp[i][0] = 1;
        for(int i=1;i<=n;i++) {
            for(int j=1;j<=m;j++) {
                int take=0,takei=0;
                if(s[i-1]==t[j-1])
                    take = dp[i-1][j-1];
                takei = dp[i-1][j];
                dp[i][j] = take+takei;
            }
        }
        return dp[n][m];
    }
};
//Time complexity: O(n*n)
//Space complexity: O(n*n) 