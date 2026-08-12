class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        string res = "";
        int n = min(word1.size(),word2.size()),j=0,k=0;
        for(int i=0;i<2*n;i++) {
            if(i%2 == 0)
                res += word1[j++];
            else
                res += word2[k++];
        }
        while(j<word1.size())
            res += word1[j++];
        while(k<word2.size())
            res += word2[k++];
        return res;
    }
};
//Time complexity: O(n+m)
//Space complexity: O(n+m)