class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int maxi=0,n=s.size(),r=0,l=0;
        unordered_map<char,int> mpp;
        while(r<n) { //O(n)
            mpp[s[r]]++;
            while(mpp[s[r]]>1) { //O(n)
                mpp[s[l]]--;
                l++;
            }
            maxi = max(maxi,r-l+1);
            r++;
        }
        return maxi;
    }
};
//Time complexity: O(n)
//Space complexity: O(26) = O(1)