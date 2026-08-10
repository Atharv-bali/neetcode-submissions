class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int l = 0, r = 0, n = nums.size();
        while(r<n) {
            if(nums[l] == val) {
                while(r<n && nums[r]==val)
                    r++;
                if(r==n)
                    break;
            }
            int temp = nums[r];
            nums[r] = nums[l];
            nums[l] = temp;
            l++;
            r++;
        }
        return l;
    }
};
//Time complexity: O(n)
//Space complexity: O(1)