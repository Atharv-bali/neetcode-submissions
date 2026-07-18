class Solution {
public:
    int solve(int i, int b, vector<int> &prices, vector<vector<int>>& dp) {
        if(i>=prices.size())
            return 0;
        if(dp[i][b]!=-1)
            return dp[i][b];
        int buy,skipbuy,sell,skipsell;
        int profit = 0;
        if(b==0) {
            buy = -prices[i] + solve(i+1,1,prices,dp);
            skipbuy = solve(i+1,0,prices,dp);
            profit = max(buy,skipbuy);
        }
        else {
            sell = prices[i] + solve(i+2,0,prices,dp);
            skipsell = solve(i+1,1,prices,dp);
            profit = max(sell,skipsell);
        }
        return dp[i][b] = profit;
    }
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        if(n==1)
            return 0;
        vector<vector<int>> dp(n,vector<int>(2,-1));
        return solve(0,0,prices,dp);
    }
};
//Time complexity: O(n*2)
//Space complexity: O(n*2)