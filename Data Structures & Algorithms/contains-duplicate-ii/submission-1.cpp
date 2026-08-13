class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int,int> mpp;
        for(int i=0;i<min(k,n);i++) {
            if(mpp.find(nums[i])!=mpp.end())
                return true;
            mpp[nums[i]]++;
        }
        if(k>=n)
            return false;
        int l = 0, r = k;
        while(r<n) {
            if(mpp.find(nums[r])!=mpp.end())
                return true;
            mpp[nums[r]]++;
            mpp[nums[l]]--;
            if(mpp[nums[l]]==0)
                mpp.erase(nums[l]);
            l++;
            r++;
        }
        return false;
    }
};
//Time complexity: O(n)
//Space complexity: O(K)