class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        for(int num: nums) {
            int idx = abs(num)-1;
            if(nums[idx]<0)
                return num<0?-num:num;
            nums[idx]*=-1;
        }
        return -1;
    }
};
