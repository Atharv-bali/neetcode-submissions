class Solution {
public:
    // int solve(int i, vector<int> &cost, vector<int> &dp) {
    //     if(i>=cost.size())
    //         return 0;
    //     if(dp[i]!=-1)
    //         return dp[i];
    //     int take_one = cost[i] + solve(i+1,cost,dp);
    //     int take_two = cost[i] + solve(i+2,cost,dp);
    //     return dp[i] = min(take_one,take_two);
    // }
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        // vector<int> dp(n,-1);
        vector<int> dp(n+2,0);

        for(int i=n-1;i>=0;i--) {
            int take_one = cost[i] + dp[i+1];
            int take_two = cost[i] + dp[i+2];
            dp[i] = min(take_one, take_two);
        }

        int zero = dp[0];
        //int zero = solve(0,cost,dp); //O(n)
        dp.assign(n+1,0);

        for(int i=n-1;i>=1;i--) {
            int take_one = cost[i] + dp[i+1];
            int take_two = cost[i] + dp[i+2];
            dp[i] = min(take_one, take_two);
        }
        
        int one = dp[1];
        // int one = solve(1,cost,dp); //O(n)
        return min(one,zero);
    }
};
//Time complexity: O(n)
//Space complexity: O(n)