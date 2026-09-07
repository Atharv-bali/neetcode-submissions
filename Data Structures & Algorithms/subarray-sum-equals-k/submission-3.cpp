class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int,int> mpp;
        int n = nums.size(),sum,count=0;
        for(int i=0;i<n;i++) {
            sum = 0;
            for(int j=i;j<n;j++) {
                sum += nums[j];
                if(sum == k)
                    count++;
            }
        }
        return count;
    }
};
//Time complexity: O(n*n)
//Space complexity: O(1)