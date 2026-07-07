class Solution {
public:
    // int solve(int n, vector<int> &dp) {
    //     if(n<0)
    //         return 0;
    //     if(n == 0) 
    //         return 1;
    //     if(dp[n]!=-1)
    //         return dp[n];
    //     return dp[n] = solve(n-1,dp)+solve(n-2,dp);
    // }
    int climbStairs(int n) {
        // vector<int> dp(n+1,-1);
        vector<int> dp(n+1,0);
        dp[0]=1;
        for(int i=1;i<=n;i++) { //O(n)
            if(i>1)
                dp[i] = dp[i-1] + dp[i-2];
            else
                dp[i] = dp[i-1];
        }
        return dp[n];
    }
};
//Time complexity: O(n)
//Space complexity: O(n)