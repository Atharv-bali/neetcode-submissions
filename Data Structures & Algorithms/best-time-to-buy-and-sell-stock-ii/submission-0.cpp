class Solution {
public:
    int solve(int i, vector<int> &prices, int buy, vector<vector<int>>& dp) {
        if(i>=prices.size())
            return 0;
        if(dp[i][buy]!=-1)
            return dp[i][buy];
        int take = -1e8,nottake = -1e8;
        if(buy == 0) {
            take = -prices[i] + solve(i+1,prices,1,dp);
            nottake = solve(i+1,prices,0,dp);
        }
        else {
            take = prices[i] + solve(i+1,prices,0,dp);
            nottake = solve(i+1,prices,1,dp);
        }
        return dp[i][buy] = max(take,nottake);
    }
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n+1,vector<int>(2,-1));
        return solve(0,prices,0,dp);
    }
};
//Time complexity: O(n)
//Space complexity: O(n)