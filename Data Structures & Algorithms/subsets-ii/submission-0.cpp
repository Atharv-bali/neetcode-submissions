class Solution {
public:
    void solve(int ind, vector<int> &nums, vector<int> &ans, vector<vector<int>> &res) {
        res.push_back(ans);
        for(int i=ind;i<nums.size();i++) { //O(n)
            if(i!=ind && nums[i]==nums[i-1])
                continue;
            ans.push_back(nums[i]);
            solve(i+1,nums,ans,res);
            ans.pop_back();
        }
        return;
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<int> ans = {};
        vector<vector<int>> res;
        solve(0,nums,ans,res); //O(2^n)
        return res;
    }
};
//Time complexity: O(n*2^n)
//Space complexity: O(n*2^n)