class Solution {
public:
    void solve(int idx, string &digits, vector<string> &res, string &ans, unordered_map<char, string> &mpp) {
        if(idx>=digits.size()) {
            res.push_back(ans);
            return;
        }
        char c = digits[idx];
        string str = mpp[c];
        for(int i=0;i<str.size();i++) {
            ans.push_back(str[i]);
            solve(idx+1,digits,res,ans,mpp);
            ans.pop_back();
        }
        return;
    }    
    
    vector<string> letterCombinations(string digits) {
        if(digits.size()==0)
            return {};
        unordered_map<char, string> mpp;
        mpp['2'] = "abc";
        mpp['3'] = "def";
        mpp['4'] = "ghi";
        mpp['5'] = "jkl";
        mpp['6'] = "mno";
        mpp['7'] = "pqrs";
        mpp['8'] = "tuv";
        mpp['9'] = "wxyz";
        vector<string> res;
        string ans="";
        solve(0,digits,res,ans,mpp);
        return res;

    }
};
//Time complexity: O(4^N*N)
//Space complexity: O(length of digits)