class Solution {
public:
    // int solve(int i, vector<int> &nums, vector<int> &dp) {
    //     if(i>=nums.size())
    //         return 0;
    //     if(dp[i]!=-1)
    //         return dp[i];
    //     int take = nums[i] + solve(i+2,nums,dp);
    //     int nottake = solve(i+1,nums,dp);
    //     return dp[i] = max(take,nottake);
    // }
    int rob(vector<int>& nums) {
        int n = nums.size();
        // vector<int> dp(n,-1);
        vector<int> dp(n+2,0);
        int take=0,nottake=0;
        for(int i=n-1;i>=0;i--) {

            take = nums[i] + dp[i+2];
            nottake = dp[i+1];
            dp[i] = max(take,nottake);
            
        }
        return dp[0];
    }
};
//Time complexity: O(n)
//Space complexity: O(n)