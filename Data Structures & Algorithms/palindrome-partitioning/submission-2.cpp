class Solution {
public:
    bool check(int i, int j, string s) {
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
        for(int i=index;i<s.size();i++) { //O(2^n)
            if(check(index,i,s)) {
                ans.push_back(s.substr(index,i-index+1));
                solve(i+1,s,ans,res);
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
//Time complexity: O(2^n*n)
//Space complexity: O(n)