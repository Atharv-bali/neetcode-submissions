class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<vector<int>> dp(n+1,vector<int>(amount+2,0));
        for(int i=0;i<=n;i++) 
            dp[i][0] = 1;

        for(int i=n-1;i>=0;i--) {
            for(int j=0;j<=amount;j++) {
                int take = 0, nottake = 0;
                if(j>=coins[i]) 
                    take = dp[i][j-coins[i]];
                nottake = dp[i+1][j];
                dp[i][j] = take+nottake;
            }
        }
        return dp[0][amount];
    }
};
//Time complexity: O(n*amount)
//Space complexity: O(n*amount)