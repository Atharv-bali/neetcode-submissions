class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int n = strs.size();
        string res = "";
        for(string str:strs) {
            if(str == "")
                return "";
            else if(res == "") {
                res = str;
                continue;
            }
            int i = 0;
            for(char &c:str) {
                if(i>=res.size() || c != res[i]) 
                    break;
                
                i++;
            }
            res = res.substr(0,i);
            if(res == "")
                return res;
        }
        return res;
    }
};