class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        int first,second,result;
        string str;
        stack<string> st;
        for(string &s:tokens) { //O(n)
            if(s=="+"||s=="-"||s=="*"||s=="/") {
                second = stoi(st.top());
                st.pop();
                first = stoi(st.top());
                st.pop();
                if(s=="+") {
                    result = first+second;
                    str = to_string(result);
                    st.push(str);
                }
                else if(s=="-") {
                    result = first-second;
                    str = to_string(result);
                    st.push(str);
                }
                else if(s=="*") {
                    result = first*second;
                    str = to_string(result);
                    st.push(str);
                }
                else if(s=="/") {
                    result = first/second;
                    str = to_string(result);
                    st.push(str);
                }
            }
            else
                st.push(s);
        }
        return stoi(st.top());
    }
};
//Time complexity: O(n)
//Space complexity: O(n)
