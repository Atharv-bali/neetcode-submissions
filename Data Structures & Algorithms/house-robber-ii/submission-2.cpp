class Solution {
public:
    // int solve(int i, vector<int>& nums, int limit, vector<int> &dp) {
    //     if(i>=limit) 
    //         return 0;
    //     if(dp[i]!=-1)
    //         return dp[i];
    //     int take = nums[i] + solve(i+2,nums,limit,dp);
    //     int nottake = solve(i+1,nums,limit,dp);
    //     return dp[i] = max(take,nottake);
    // }
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n==1)
            return nums[0];
        // vector<int> dp(n,-1);
        vector<int> dp(n+2,0);
        for(int i=n-2;i>=0;i--) {
            int take = nums[i] + dp[i+2];
            int nottake = dp[i+1];
            dp[i] = max(take,nottake);
        }
        int first = dp[0];
        dp.assign(n,-1);
        for(int i=n-1;i>=1;i--) {
            int take = nums[i] + dp[i+2];
            int nottake = dp[i+1];
            dp[i] = max(take,nottake);
        }
        int last = dp[1];
        return max(last,first);
    }
};
//Time complexity: O(n)
//Space complexity: O(n)