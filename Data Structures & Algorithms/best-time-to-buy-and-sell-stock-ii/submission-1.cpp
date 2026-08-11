class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        // vector<vector<int>> dp(n+1,vector<int>(2,-1));
        vector<vector<int>> dp(n+1,vector<int>(2,0));
        for(int i=n-1;i>=0;i--) {
            for(int buy=1;buy>=0;buy--) {
                int take = -1e8,nottake = -1e8;
                if(buy == 0) {
                    take = -prices[i] + dp[i+1][1];
                    nottake = dp[i+1][0];
                }
                else {
                    take = prices[i] + dp[i+1][0];
                    nottake = dp[i+1][1];
                }
                dp[i][buy] = max(take,nottake);
            }
        }
        return dp[0][0];
    }
};
//Time complexity: O(n)
//Space complexity: O(n)