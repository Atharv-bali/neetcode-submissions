class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        for(char &c:s) { //O(n)
            if(!st.empty() && (st.top()=='(' && c==')' || st.top()=='{' && c=='}' || st.top()=='[' && c==']')) 
                st.pop();
            else
                st.push(c);
        }
        return st.empty();
    }
};
//Time complexity: O(n)
//Space complexity: O(n)