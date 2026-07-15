class Solution {
public:
    bool isValid(string curr) {
        stack<char> st;
        for(char &c:curr) { //O(n)
            if(!st.empty() && st.top()=='(' && c == ')')
                st.pop();
            else
                st.push(c);
        }
        return st.size()==0;
    }
    void solve(string curr, int n, vector<string> &res) {
        
        if(curr.size()==2*n) {
            if(isValid(curr))
                res.push_back(curr);
            return;
        }
        // O(2*n)
        curr.push_back('(');
        solve(curr,n,res);
        curr.pop_back();
        curr.push_back(')');
        solve(curr,n,res);
        curr.pop_back();
        return;
    }
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        solve("",n,res); //O(n*2^2n)
        return res;
    }
};
//Time complexity: O(n*2^2n)
//Space complexity: (excluding res) O(2*n)