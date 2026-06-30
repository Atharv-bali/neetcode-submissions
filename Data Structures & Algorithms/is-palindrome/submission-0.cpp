class Solution {
public:
    bool isPalindrome(string s) { 
        string str="";
        for(char &ch:s) { //O(n)
            if((ch>='a' && ch<='z')||(ch>='A'&&ch<='Z')||(ch>='0'&&ch<='9'))
                str+=tolower(ch);
        }
        int n = str.size();
        for(int i=0;i<n/2;i++) { // O(n)
            if(str[i]!=str[n-i-1])
                return false;
        }
        return true;
    }
};
// Time complexity: O(n)
// Space complexity: O(n)