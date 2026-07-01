class Solution {
public:
    int findMin(vector<int> &nums) {
        int l=0,r=nums.size()-1,mini=1e7;
        while(l<=r) { //O(logn)
            int mid=l+(r-l)/2;
            if(nums[mid]>nums[l] && nums[mid]<nums[r])
                return nums[l];
            else if(nums[mid]>=nums[l]) {
                mini = min(mini,nums[l]);
                l=mid+1;
            }
            else if(nums[mid]<nums[r]) {
                mini = min(mini,nums[mid]);
                r=mid-1;
            }
        }
        return mini;
    }
};
//Time complexity: O(logn)
//Space complexity: O(1)
