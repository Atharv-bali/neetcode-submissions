class Solution {
public:
    string minWindow(string s, string t) {
        int r = 0, l = 0, n = s.size(), m = t.size(), cnt = 0, start = -1, minlen = 1e8;
        unordered_map<char,int> mpp;
        for(int i=0;i<m;i++) //O(m)
            mpp[t[i]]++;
        while(r<n) { // O(n)
            mpp[s[r]]--;
            if(mpp[s[r]]>=0) {
                cnt = cnt+1;
            }
            while(cnt == m) { //O(n)
                if(r-l+1 < minlen) {
                    minlen = r-l+1;
                    start = l;
                }
                mpp[s[l]]++;
                if(mpp[s[l]]>0) {
                    cnt--;
                }
                l++;
            }
            r++;
        }
        return start==-1?"":s.substr(start,minlen);
    }
};
//Time complexity: O(2*n+m)
//Space complexity: O(n)