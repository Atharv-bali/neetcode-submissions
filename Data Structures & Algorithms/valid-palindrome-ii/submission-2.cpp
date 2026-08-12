class Solution {
public:
    bool palindrome(string &s, int l, int r) {
        while(l<=r) {
            if(s[l]!=s[r])
                return false;
            l++;
            r--;
        }
        return true;
    }
    bool validPalindrome(string s) {
        int n = s.size();
        int l = 0, r = s.size()-1, k = 0;
        while(l<=r) {
            if(s[l]!=s[r])
                return palindrome(s,l+1,r) || palindrome(s,l,r-1);
            l++;
            r--;
        }
        return true;
    }
};
//Time complexity: O(n)
//Space complexity: O(1)