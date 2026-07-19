class Solution {
public:
    int solve(int i, vector<int>& nums, vector<int>& dp) {
        if(i==nums.size()-1)
            return 0;
        if(i>=nums.size())
            return 0;
        if(dp[i]!=-1)
            return dp[i];
        if(nums[i]==0)
            return 1e8;
        int result = nums.size();
        for(int ind=1;ind<=nums[i];ind++) {
            result = min(result,1+solve(ind+i,nums,dp));
        }
        return dp[i] = result;
    }
    int jump(vector<int>& nums) {
        int n = nums.size();
        vector<int>dp(n,-1);
        return solve(0,nums,dp);
    }
};
//Time complexity: O(n^2)
//Space complexity: O(n^2)