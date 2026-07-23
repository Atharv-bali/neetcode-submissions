class Solution {
public:
    vector<int> partitionLabels(string s) {
        unordered_map<int,int> mpp;
        vector<int> res;
        int count = 0; 
        for(char &ch:s) 
            mpp[ch-'a']++;
        set<int> st;
        for(char &ch:s) {
            if(st.find(ch-'a') == st.end()) {
                count += mpp[ch-'a'];
                // mpp[ch-'a']--;
                st.insert(ch-'a');
            } 
            if(mpp[ch-'a']>0) {
                mpp[ch-'a']--;
                if(mpp[ch-'a']==0) {
                    st.erase(ch-'a');
                    mpp.erase(ch-'a');
                }
            }
            if(st.empty()) {
                res.push_back(count);
                count = 0;
            }
        }
        if(count!=0)
            res.push_back(count);
        return res;
    }
};
