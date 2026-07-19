class Solution {
public:
    bool solve(int i, int j, string &s1, string &s2, string &s3, vector<vector<int>>& dp) {
        if(i==s1.size() && j==s2.size() && (i+j)==s3.size())
            return true;
        if((i+j)>=s3.size())
            return false;
        if(dp[i][j]!=-1)
            return dp[i][j];
        bool result = false;
        if(i<s1.size() && (i+j)<s3.size() && s1[i]==s3[i+j])
            result = solve(i+1,j,s1,s2,s3,dp);
        if(j<s2.size() && (i+j)<s3.size() && s2[j]==s3[i+j])
            result = solve(i,j+1,s1,s2,s3,dp);
        return dp[i][j] = result;
    }

    bool isInterleave(string s1, string s2, string s3) {
        int n = s1.size();
        int m = s2.size();
        vector<vector<int>> dp(n+1,vector<int>(m+1,-1));
        return solve(0,0,s1,s2,s3,dp);
    }
};
