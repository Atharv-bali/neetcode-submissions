class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxSum=-1e6,currSum=-1e6;
        for(int &num:nums) {
            currSum = max(currSum+num,num);
            maxSum = max(maxSum,currSum);
        }
        return maxSum;
    }
};
//Time complexity: O(n)
//Space complexitY: O(1)