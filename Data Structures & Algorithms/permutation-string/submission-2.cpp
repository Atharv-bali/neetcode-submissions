class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        vector<int> count(26,0);
        int l=0,r=0,cnt=0,n=s2.size();
        for(char &ch:s1) { //O(m)
            count[ch-'a']++;
            cnt++;
        }
        for(r=0;r<s1.size()-1;r++) { //O(m)
            count[s2[r]-'a']--;
            if(count[s2[r]-'a']>=0) 
                cnt--;
        }
        while(r<n) { //O(n)
            count[s2[r]-'a']--;
            if(count[s2[r]-'a']>=0)
                cnt--;
            if(cnt == 0)
                return true;
            count[s2[l]-'a']++;
            if(count[s2[l]-'a']>0)
                cnt++;
            l++;
            r++;
        }
        return false;
    }
};
//Time complexity: O(n+2m)
//Space complexity: O(26)