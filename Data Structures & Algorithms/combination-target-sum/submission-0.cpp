class Solution {
public:
    void solve(int i, vector<int> &nums, int target, vector<int> &ans, vector<vector<int>> &res) {

        if(target == 0) {
            res.push_back(ans);
            return;
        }

        if(i>=nums.size() || target<0)
            return;

        ans.push_back(nums[i]);
        solve(i,nums,target-nums[i],ans,res);
        ans.pop_back();
        solve(i+1,nums,target,ans,res);

    }
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<int> ans;
        vector<vector<int>> res;

        solve(0,nums,target,ans,res);

        return res;
    }
};
//Time complexity: O(2^t*k), t is maximum recursive depth, k is average length of combinations
//Space complexity: O(2^t*k)
