class Solution {
public:
    void solve(int ind, vector<int>& candidates, int target, vector<vector<int>> &res, vector<int>& ans) {
        if(target==0) {
            res.push_back(ans);
            return;
        }

        if(ind>=candidates.size() || target<0)
            return;

        for(int i=ind;i<candidates.size();i++) { //O(n)
            if(i!=ind && candidates[i]==candidates[i-1])
                continue;
            ans.push_back(candidates[i]);
            solve(i+1,candidates,target-candidates[i],res,ans);
            ans.pop_back();
        }

        return;
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        vector<int> ans;
        sort(candidates.begin(),candidates.end());
        solve(0,candidates,target,res,ans); //O(2^k), k is max depth of recursive tree
        return res;
    }
};

//Time complexity: O(n*2^k)
//Space complexity: O(n*2^k)