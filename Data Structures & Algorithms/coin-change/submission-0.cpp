class Solution {
public:
    int solve(int i, int amount, vector<int> &coins, vector<vector<int>> &dp) {
        if(i<0) {
            return 1e8;
        }

        if(dp[i][amount]!=-1)
            return dp[i][amount];

        if(amount%coins[i]==0)
            return amount/coins[i];

        int take=1e8,nottake=1e8;
        if(amount>coins[i])
            take = 1+solve(i,amount-coins[i],coins,dp);
        nottake = solve(i-1,amount,coins,dp);
        return dp[i][amount] = min(take,nottake); 
    }
    int coinChange(vector<int>& coins, int amount) {
        sort(coins.begin(),coins.end());
        int n = coins.size();
        vector<vector<int>> dp(n+1,vector<int>(amount+1,-1));
        return solve(coins.size()-1,amount,coins,dp)>1e7?-1:solve(coins.size()-1,amount,coins,dp);
    }
};
//Time complexity: O(N*amount)
//Space complexity: O(N*amount)