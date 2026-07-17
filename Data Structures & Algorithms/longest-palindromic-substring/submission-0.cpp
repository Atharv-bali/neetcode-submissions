class Solution {
public:
    bool solve(int i, int j, string &s) { //O(logn)
        if(i>=j)
            return true; 
        if(s[i]==s[j]) {
            return solve(i+1,j-1,s);
        }
        return false;
    }
    string longestPalindrome(string s) {
        int n = s.size(),i=0,j=n-1,len=0;
        string res="";
        for(int i=0;i<n;i++) { //O(n)
            for(int j=i;j<n;j++) { //O(n)
                if(solve(i,j,s)) {
                    if(len < (j-i+1)) {
                        len = j-i+1;
                        res = s.substr(i,len);
                    }
                }
            }
        }
        return res;
    }
};
//Time complexity: O(n^2logn)
//Space complexity: O(n)