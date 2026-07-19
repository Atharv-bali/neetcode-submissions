class Solution {
public:
    bool solve(int ind, vector<int>& nums, vector<int> &dp) {
        if(ind==nums.size()-1)
            return true;
        if(dp[ind]!=-1)
            return dp[ind];
        for(int i=1;i<=nums[ind];i++) {
            if(solve(ind+i,nums,dp))
                return dp[ind] = true;
        }
        return dp[ind] = false;
    }
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n,-1);
        return solve(0,nums,dp);
    }
};
//Time complexity: O(n)
//Space complexity: O(n)