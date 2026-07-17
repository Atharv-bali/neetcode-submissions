class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int total=0,n=nums.size();
        for(int &num:nums)
            total += num;
        if(total%2)
            return false;
        vector<vector<int>> dp(n+1,vector<int>(total/2+1,0));
        for(int i=0;i<=n;i++)
            dp[i][0] = 1;
        for(int i=n-1;i>=0;i--) {
            for(int target=0;target<=total/2;target++) {
                int take=0,nottake=0;
                if(target>=nums[i])
                    take = dp[i+1][target-nums[i]];
                nottake = dp[i+1][target];
                dp[i][target] = take || nottake;
            }
        }
        return dp[0][total/2];
    }
};
//Time complexity: O(n*total/2)
//Space complexity: O(n*total/2)