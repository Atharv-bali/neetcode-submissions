class Solution {
public:
    int characterReplacement(string s, int k) {
        vector<int> count(26,0);
        int l=0,r=0,maxi=0,maxlen=0,n=s.size();
        while(r<n) { //O(n)
            count[s[r]-'A']++;
            maxi=max(maxi,count[s[r]-'A']);
            int res = r-l+1-maxi;
            while(res>k) { //O(n)
                maxi=0;
                count[s[l]-'A']--;
                for(int i=0;i<=25;i++) //O(26)
                    maxi = max(maxi,count[i]);
                l++;
                res = r-l+1-maxi;
            }
            if(res<=k)
                maxlen = max(maxlen,r-l+1);
            r++;
        }
        return maxlen;
    }
};
//Time complexity: O((n+n)*26)
//Space complexity: O(26)
