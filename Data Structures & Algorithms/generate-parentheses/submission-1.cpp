class Solution {
public:
    void solve(string curr, int n, vector<string> &res, int open, int close) {
        
        if(curr.size()==2*n) {
            res.push_back(curr);
            return;
        }
        if(open<n) {
            curr.push_back('(');
            solve(curr,n,res,open+1,close);
            curr.pop_back();
        }
        if(close<open) {
            curr.push_back(')');
            solve(curr,n,res,open,close+1);
            curr.pop_back();
        }
        return;
    }
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        int open=0,close=0;
        solve("",n,res,open,close); //O(n*2^2n)
        return res;
    }
};
//Time complexity: O(2^2n)
//Space complexity: (excluding res) O(2*n)