class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int zero=0, n=nums.size(), prod=1, zeroi=-1;
        vector<int> res(n,0);
        for(int i=0;i<n;i++) { //O(n)
            if(nums[i]==0) {
                zero++;
                zeroi=i;
            }
            else
                prod = prod*nums[i];
        }
        if(zero>1)
            return res;
        else if(zeroi!=-1) {
            res[zeroi]=prod;
            return res;
        }
        else {
            for(int i=0;i<n;i++) //O(n)
                res[i] = prod/nums[i];
        }
        return res;
    }
    //Time complexity: O(n)
    // Space complexity: O(n), due to res vector
};
