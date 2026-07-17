class Solution {
public:
    bool solve(int i, int target, vector<int> &nums, vector<vector<int>> &dp) {
        if(target==0)
            return true;
        if(i>=nums.size())
            return false;
        if(dp[i][target]!=-1)
            return dp[i][target];
        int take=0,nottake=0;
        if(target>=nums[i])
            take = solve(i+1,target-nums[i],nums,dp);
        nottake = solve(i+1,target,nums,dp);
        return dp[i][target] = take || nottake;
    }
    bool canPartition(vector<int>& nums) {
        int total=0,n=nums.size();
        for(int &num:nums)
            total += num;
        if(total%2)
            return false;
        vector<vector<int>> dp(n+1,vector<int>(total/2+1,-1));
        return solve(0,total/2,nums,dp);
    }
};
//Time complexity: O(n*total/2)
//Space complexity: O(n*total/2)