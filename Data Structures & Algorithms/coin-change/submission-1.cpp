class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        sort(coins.begin(),coins.end());
        int n = coins.size();
        vector<vector<int>> dp(n+1,vector<int>(amount+1,1e8));
        for(int i=0;i<=n;i++)
            dp[i][0] = 0;
        for(int i=1;i<=n;i++) {
            for(int j=1;j<=amount;j++) {
                int take=1e8,nottake=1e8;
                if(j>=coins[i-1])
                    take = 1+dp[i][j-coins[i-1]];
                nottake = dp[i-1][j];
                dp[i][j] = min(take,nottake); 
            }
        }
        return dp[n][amount]>1e7?-1:dp[n][amount];
    }
};
//Time complexity: O(N*amount)
//Space complexity: O(N*amount)