class Solution {
public:
    int solve(int i, int j, string &s, vector<vector<int>>& dp) { //O(logn)
        if(i>=j)
            return 1; 
        if(dp[i][j]!=-1)
            return dp[i][j];
        if(s[i]==s[j]) {
            return dp[i][j] = solve(i+1,j-1,s,dp);
        }
        return dp[i][j] = 0;
    }
    string longestPalindrome(string s) {
        int n = s.size(),i=0,j=n-1,len=0;
        vector<vector<int>> dp(n,vector<int>(n,-1));
        string res="";
        for(int i=0;i<n;i++) { //O(n)
            for(int j=i;j<n;j++) { //O(n)
                if(solve(i,j,s,dp)) {
                    if(len < (j-i+1)) {
                        len = j-i+1;
                        res = s.substr(i,len);
                    }
                }
            }
        }
        return res;
    }
};
//Time complexity: O(n^2)
//Space complexity: O(n)