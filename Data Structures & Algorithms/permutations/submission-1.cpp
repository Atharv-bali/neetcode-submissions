class Solution {
public:
    void recur(int ind, vector<int> &nums, vector<vector<int>> &res) {
        if(ind == nums.size()) {
            res.push_back(nums);
            return;
        }
        for(int i=ind;i<nums.size();i++) { //O(n)
            int temp = nums[i];
            nums[i] = nums[ind];
            nums[ind] = temp;
            recur(ind+1,nums,res);
            temp = nums[i];
            nums[i] = nums[ind];
            nums[ind] = temp;
        }
        return;
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        int n = nums.size();
        recur(0,nums,res); //O(n!)
        return res;
    }
};
//Time complexity: O(n!*n)
//Space complexity: O(1)