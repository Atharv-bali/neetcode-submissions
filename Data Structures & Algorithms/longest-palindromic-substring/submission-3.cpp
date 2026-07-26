class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        string LPS = "";
        if(n==1)
            return s;
        for(int i=1;i<n;i++) {
            int high=i,low=i;
            string palindrome="";
            while(low>=0 && high<n && s[low]==s[high]) {
                palindrome = s.substr(low,high-low+1);
                if(palindrome.size()>LPS.size())
                    LPS = palindrome;
                low--;
                high++;
            }
            high=i,low=i-1;
            while(low>=0 && high<n && s[low]==s[high]) {
                palindrome = s.substr(low,high-low+1);
                if(palindrome.size()>LPS.size())
                    LPS = palindrome;
                low--;
                high++;
            }
        }
        return LPS;
    }
};
//Time complexity: O(n^2)
//Space complexity: O(n)