class Solution {
public:
    int characterReplacement(string s, int k) {
        vector<int> count(26,0);
        int l=0,r=0,maxi=0,maxlen=0,n=s.size();
        while(r<n) { //O(n)
            count[s[r]-'A']++;
            maxi=max(maxi,count[s[r]-'A']);
            int res = r-l+1-maxi;
            if (res>k) { 
                maxi=0;
                count[s[l]-'A']--;
                l++;
            }
            else if(res<=k)
                maxlen = max(maxlen,r-l+1);
            r++;
        }
        return maxlen;
    }
};
//Time complexity: O((n)
//Space complexity: O(26)
