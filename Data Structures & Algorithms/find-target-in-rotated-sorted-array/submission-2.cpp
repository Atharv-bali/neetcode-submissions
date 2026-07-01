class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l=0,r=nums.size()-1,mid;
        while(l<=r) { //O(logn)
            mid = l+(r-l)/2;
            if(nums[mid]==target)
                return mid;
            else if(nums[l]<=nums[mid]) {
                if(nums[l]<=target && nums[mid]>target) {
                    r=mid-1;
                }
                else 
                    l=mid+1;
            }
            else if(nums[r]>=nums[mid]) {
                if(nums[r]>=target && nums[mid]<target) {
                    l=mid+1;
                }
                else
                    r=mid-1;
            }
        }
        return -1;
    }
};
//Time complexity: O(logn)
//Space complexity: O(1)