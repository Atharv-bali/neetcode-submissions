class Solution {
public:
    int solve(int i, string &s, vector<int> &dp) {
        if(i>=s.size())
            return 1;
        if(dp[i]!=-1)
            return dp[i];
        if(s[i]=='0')
            return 0;
        
        int take_one = solve(i+1,s,dp);
        int take_two=0;
        if(i+1<s.size() && (s[i]=='1' || s[i]=='2' && s[i+1]<='6')) 
            take_two = solve(i+2,s,dp);
        return dp[i] = take_one + take_two;
    }
    int numDecodings(string s) {
        int n = s.size();
        vector<int> dp(n+1,-1);
        return solve(0,s,dp);
    }
};
//Time complexity: O(N+1)
//Space complexity: O(N+1)