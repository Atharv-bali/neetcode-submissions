class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        // vector<vector<int>> dp(n,vector<int>(n,-1));
        vector<vector<int>> dp(n+1,vector<int>(n+1,0));
        for(int i=n-1;i>=0;i--) {
            for(int prev=i-1;prev>=-1;prev--) {
                int take=-1e8,nottake=-1e8;
                if(prev==-1 || nums[i]>nums[prev])
                    take = 1+dp[i+1][i+1];
                nottake = dp[i+1][prev+1];
                dp[i][prev+1] = max(take,nottake);
            }
        }
        return dp[0][0];
    }
};
//Time complexity: O(n^2)
//Space complexity: O(n^2)