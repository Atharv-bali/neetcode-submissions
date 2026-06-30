class Solution {
public:
    //  Time complexity: O(n)
    string encode(vector<string>& strs) {
        int n = strs.size();
        string s="";
        if(n==0)
            return "";
        //O(n)
        for(string &str:strs)
            s += str+"-";
        return s;
    }
    //  Time complexity: O(n)
    // Space complexity: O(n), n is size of ans
    vector<string> decode(string s) {
        int n = s.size();
        if(s=="")
            return {};
        string str="";
        vector<string> ans;
        for(int i=0;i<n-1;i++) { //O(n)
            if(s[i]!='-') {
                str += s[i];
            }
            else if(s[i]=='-') {
                ans.push_back(str);
                str="";
            }
        }
        ans.push_back(str);
        return ans;
    }
};
