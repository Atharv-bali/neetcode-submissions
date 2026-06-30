class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n = nums.size();
        vector<vector<int>> res;
        for(int i=0;i<n-2;i++) { //O(n)
            if(i!=0 && nums[i]==nums[i-1])
                continue;
            int j=i+1,k=n-1;
            while(j<k) { //O(n)
                int target = nums[i]+nums[j]+nums[k];
                if(target==0) {
                    res.push_back({nums[i],nums[j],nums[k]});
                    j++;
                    k--;
                    while(j<k && nums[j]==nums[j-1])
                        j++;
                    while(j<k && nums[k]==nums[k+1])
                        k--;
                }
                else if(target<0) 
                    j++;
                else
                    k--;
            }
        }
        return res;
    }
};
//Time complexity: O(n^2)
//Space complexity: O(1)
