class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<string>> mpp;
        string s;
        vector<vector<string>> ans;
        for(string &str:strs) {
            s = str;
            sort(s.begin(),s.end());
            mpp[s].push_back(str);
        }
        for(auto &it:mpp) {
            ans.push_back(it.second);
        }
        return ans;
    }
};
