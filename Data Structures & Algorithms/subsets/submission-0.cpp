class Solution {
public:
    void solve(int ind, vector<int> &nums, vector<vector<int>> &res, vector<int> &ans) {
        res.push_back(ans);
        for(int i=ind;i<nums.size();i++) { //O(n)
            ans.push_back(nums[i]);
            solve(i+1,nums,res,ans);
            ans.pop_back();
        }
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> ans = {};
        solve(0,nums,res,ans); // O(2^n)
        return res;
    }
};
//Time complexity: O(n*2^n)
//Space complexity: O(n*2^n)