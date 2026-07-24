class Solution {
public:
    vector<int> minInterval(vector<vector<int>>& intervals, vector<int>& queries) {
        vector<int> res(1e5,1e8);
        for(auto &it:intervals) {
            int first = it[0];
            int second = it[1];
            for(int i=first;i<=second;i++) {
                res[i] = min(res[i],second-first+1);
            }
        }
        vector<int> ans;
        for(int &it:queries)
            ans.push_back(res[it]==1e8?-1:res[it]);
        return ans;
    }
};
