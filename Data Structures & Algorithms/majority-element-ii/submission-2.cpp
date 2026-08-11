class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        unordered_map<int,int> mpp;
        int n = nums.size();
        vector<int> ans;
        for(int &num:nums)
            mpp[num]++;
        for(auto &it:mpp) {
            if(it.second > n/3)
                ans.push_back(it.first);
        }
        return ans;
    }
};
//Time complexity: O(n)
//Space complexity: O(n)