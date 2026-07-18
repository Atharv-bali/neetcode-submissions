class Solution {
public:
    int solve(int i, int target, vector<int> &nums, vector<vector<int>> &dp) {
        if(i>=nums.size()) {
            if(target == 0)
                return 1;
            return 0;
        }
        if(dp[i][target]!=-1)
            return dp[i][target];
        int take = 0,nottake = 0;
        if(target>=nums[i])
            take = solve(i+1,target-nums[i],nums,dp);
        nottake = solve(i+1,target,nums,dp);
        return dp[i][target] = take+nottake;
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        int sum = 0,n=nums.size();
        for(int &num:nums)
            sum += num;
        if((sum+target)%2)
            return 0;
        int amount = (sum + target)/2;
        vector<vector<int>> dp(n,vector<int>(amount+1,-1));
        return solve(0,amount,nums,dp);
    }
};
//Time complexity: O(n*amount)
//Space complexity: O(n*amount)