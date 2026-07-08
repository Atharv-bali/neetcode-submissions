class Solution {
public:
    int solve(int i, vector<int>& nums, int limit, vector<int> &dp) {
        if(i>=limit) 
            return 0;
        if(dp[i]!=-1)
            return dp[i];
        int take = nums[i] + solve(i+2,nums,limit,dp);
        int nottake = solve(i+1,nums,limit,dp);
        return dp[i] = max(take,nottake);
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n==1)
            return nums[0];
        vector<int> dp(n,-1);
        int first = solve(0,nums,n-1,dp);
        dp.assign(n,-1);
        int last = solve(1,nums,n,dp);
        return max(last,first);
    }
};
//Time complexity: O(n)
//Space complexity: O(n)