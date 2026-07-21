class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size(),xors=n;
        for(int i=0;i<n;i++)
            xors = xors^nums[i]^i;
        return xors;
    }
};
