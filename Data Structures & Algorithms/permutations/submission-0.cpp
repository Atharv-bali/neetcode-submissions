class Solution {
public:
    void recur(vector<int> &nums, vector<int> &ds, vector<int>& freq, vector<vector<int>> &res) {
        if(nums.size() == ds.size()) {
            res.push_back(ds);
            return;
        }
        for(int i=0;i<nums.size();i++) { //O(n)
            if(!freq[i]) {
                freq[i] = 1;
                ds.push_back(nums[i]);
                recur(nums,ds,freq,res);
                freq[i] = 0;
                ds.pop_back();
            }
        }
        return;
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        int n = nums.size();
        vector<int> ds;
        vector<int> freq(n,0);
        recur(nums,ds,freq,res); //O(n!)
        return res;
    }
};
//Time complexity: O(n!*n)
//Space complexity: O(n) + O(n)