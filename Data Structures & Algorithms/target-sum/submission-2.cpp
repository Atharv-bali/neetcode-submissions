class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int sum = 0,n=nums.size();
        for(int &num:nums)
            sum += num;
        if((sum+target)%2)
            return 0;
        int amount = (sum + target)/2;
        // vector<vector<int>> dp(n,vector<int>(amount+1,-1));
        vector<vector<int>> dp(n+1,vector<int>(amount+1,0));
        dp[n][0] = 1;
        for(int i=n-1;i>=0;i--) {
            for(int j=0;j<=amount;j++) {
                int take = 0,nottake = 0;
                if(j>=nums[i])
                    take = dp[i+1][j-nums[i]];
                nottake = dp[i+1][j];
                dp[i][j] = take+nottake;
            }
        }
        return dp[0][amount];
    }
};
//Time complexity: O(n*amount)
//Space complexity: O(n*amount)