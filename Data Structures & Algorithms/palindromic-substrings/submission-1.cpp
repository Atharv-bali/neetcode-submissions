class Solution {
public:
    int target(int i, int j, string &s) {
        int count = 0;
        while(i>=0 && j<s.size() && s[i]==s[j]) {
            count++;
            i--;
            j++;
        }
        return count;
    }
    int countSubstrings(string s) {
        int n = s.size(),total=0;
        for(int i=0;i<n;i++) {
            total += target(i,i,s);
            if(i!=n-1)
                total += target(i,i+1,s);
        }
        return total;
    }
};
//Time complexity: O(n^2)
//Space complexity: O(1)