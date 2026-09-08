class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();
        vector<bool> seen(n,false);
        for(int i=0;i<n;i++) {
            if(nums[i]>0 && nums[i]<=n) 
                seen[nums[i]-1] = true;
        }
        for(int i=0;i<n;i++) {
            if(!seen[i])
                return i+1;
        }
        return n+1;
    }
};
//Time complexity: O(n)
// Space complexity: O(n)