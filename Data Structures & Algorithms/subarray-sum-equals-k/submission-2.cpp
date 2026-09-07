class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        // int l=0,r,n=nums.size(),count=0;
        // while(l<n) {
        //     r = l;
        //     while(r<n) {
        //         int sum = 0;
        //         for(int i=l;i<=r;i++) 
        //             sum += nums[i];
        //         if(sum == k)
        //             count++;
        //         r++;
        //     }
        //     l++;
        // }
        // return count;
        int n = nums.size(),count=0,sum=0,l=0,r=0;
        vector<int> prefSum(n,0);
        for(int i=0;i<n;i++) {
            if(i==0)
                prefSum[i] = nums[i];
            else
                prefSum[i] = prefSum[i-1] + nums[i];
        }
        while(l<n) {
            r = l;
            while(r<n) {
                if(l==0)
                    sum = prefSum[r];
                else
                    sum = prefSum[r] - prefSum[l-1];
                if(sum == k)
                    count++;
                r++;
            }
            l++;
        }
        return count;
    }
};
//Time complexity: O(n*n)
//Space complexity: O(n)