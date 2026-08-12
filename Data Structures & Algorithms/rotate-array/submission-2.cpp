class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        k = k%n;

        reverse(nums.end()-k,nums.end());
        reverse(nums.begin(),nums.begin()+n-k);
    
        reverse(nums.begin(),nums.end());
    }
};
//Time complexity: O(n)
//Space complexity: O(1)