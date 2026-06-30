class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int longest = 0;
        unordered_map<int,int> mpp;
        for(int &num:nums) { //O(n)
            if(!mpp[num]) {
                mpp[num] = mpp[num-1]+mpp[num+1]+1;
                mpp[num-mpp[num-1]]=mpp[num];
                mpp[num+mpp[num+1]]=mpp[num];
                longest = max(longest,mpp[num]);
            }
        }
        return longest;
    }
};
//Time complexity: O(n)
//Space complexity: O(n)