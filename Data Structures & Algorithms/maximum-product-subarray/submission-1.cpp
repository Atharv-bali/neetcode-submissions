class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int prefix=1,suffix=1,maxi=-1e9,n=nums.size();
        for(int i=0;i<n;i++) {
            prefix = prefix*nums[i];
            suffix = suffix*nums[n-i-1];
            maxi = max({suffix,prefix,maxi});
            if(prefix==0)
                prefix=1;
            if(suffix==0)
                suffix=1;
        }
        return maxi;
    }
};
//Time complexity: O(n)
//Space complexity: O(1)