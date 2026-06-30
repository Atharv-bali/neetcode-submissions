class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        sort(nums.begin(),nums.end()); // O(nlogn)
        int n = nums.size(),longest=0,maxi=0;
        for(int i=0;i<n;i++) { // O(n)
            if(i==0 || nums[i]-nums[i-1] == 1) 
                longest++;
            else if(abs(nums[i]-nums[i-1]) > 1) {
                maxi = max(maxi,longest);
                longest=1;
            }
        }  
        return max(longest,maxi);
    }
};
//Time complexity: O(nlogn)
//Space complexity: O(1)