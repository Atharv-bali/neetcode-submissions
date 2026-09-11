class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int n = nums.size(),l=0,r=n-1,ans=-1;
        while(l<=r) {
            int mid = l+(r-l)/2;
            if(nums[mid] == target)
                return mid;
            else if(nums[mid]<target) {
                ans = mid+1;
                l = mid+1;
            }
            else
                r = mid-1;
        }
        return ans==-1?0:ans;
    }
};
//Time complexity: O(logn)
//Space complexity: O(1)