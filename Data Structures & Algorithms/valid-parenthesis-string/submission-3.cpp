class Solution {
public:
    bool solve(int i, string &s, int cnt, vector<vector<int>> &dp) {
        if(cnt<0)
            return false;
        if(i==s.size())
            return cnt == 0;
        if(dp[i][cnt]!=-1)
            return dp[i][cnt];
        if(s[i] == '(')
            return dp[i][cnt] = solve(i+1,s,cnt+1,dp);
        else if(s[i]==')')
            return dp[i][cnt] = solve(i+1,s,cnt-1,dp);

        return dp[i][cnt] = solve(i+1,s,cnt,dp) || solve(i+1,s,cnt-1,dp) || solve(i+1,s,cnt+1,dp);
    }
    bool checkValidString(string s) {
        int n = s.size();
        vector<vector<int>> dp(n,vector<int>(n+1,-1));
        return solve(0,s,0,dp);
    }
};
//Time complexity: O(n*3)
//Space complexity: O(n)