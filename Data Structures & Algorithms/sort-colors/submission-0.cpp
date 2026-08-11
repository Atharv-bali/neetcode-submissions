class Solution {
public:
    void swap(int &a, int &b) {
        int temp = a;
        a = b;
        b = temp;
    }
    void sortColors(vector<int>& nums) {
        int l = 0, mid = 0, r = nums.size()-1;
        while(mid<=r) {
            if(nums[mid]==0) {
                swap(nums[l],nums[mid]);
                mid++;
                l++;
            }
            else if(nums[mid]==1)
                mid++;
            else {
                swap(nums[r],nums[mid]);
                r--;
            }
        }
    }
};
//Time complexity: O(n)
//Space complexity: O(1)