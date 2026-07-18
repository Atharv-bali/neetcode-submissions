class Solution {
public:
    unordered_set<string> st;
    bool solve(int i, string s, vector<int>& dp) {
        if(i==s.size())
            return true;
        if(dp[i]!=-1)
            return dp[i];
        for(int l=1;l<=s.size();l++) { //O(N)
            string temp = s.substr(i,l); //O(N)
            if(st.find(temp)!=st.end()) {
                if(solve(i+l,s,dp))
                    return dp[i] = true;
            }
        }
        return dp[i] = false;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        int n = s.size();
        vector<int> dp(s.size(),-1);
        st.insert(wordDict.begin(),wordDict.end());
        return solve(0,s,dp);
    }
};
//Time complexity: O(N^3)
//Space complexity: O(N*M+M)