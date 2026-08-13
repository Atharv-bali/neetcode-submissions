class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size();
        int l = 0, r = 0, minLen = 1e8, sum = 0;
        while(r<n) {
            sum += nums[r];
            while(sum >= target) {
                minLen = min(minLen,r-l+1);
                sum -= nums[l];
                l++;
            }
            r++;
        }
        return minLen>1e7?0:minLen;
    }
};
//Time complexity :O(n)
//Space compelxity: O(1)