class Solution {
public:
    bool check(string s) {
        int i=0,j=s.size()-1;
        while(i<j) {
            if(s[i]!=s[j])
                return false;
            i++;
            j--;
        }
        return true;
    }
    void solve(int index, string s, vector<string>& ans, vector<vector<string>>& res) {
        if(index>=s.size()) {
            res.push_back(ans);
            return;
        }
        for(int i=1;i<=s.size()-index;i++) {
            if(check(s.substr(index,i))) {
                ans.push_back(s.substr(index,i));
                solve(index+i,s,ans,res);
                ans.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>> res;
        vector<string> ans;
        solve(0,s,ans,res);
        return res;
    }
};
