class Solution {
public:

    static bool comp(pair<int,int> &a, pair<int,int> &b) {
        return a.first>b.first;
    }

    vector<int> topKFrequent(vector<int>& nums, int k) {

        vector<pair<int,int>> res;
        unordered_map<int,int> mpp;
        vector<int> ans;

        for(int &num:nums) { //O(n)
            mpp[num]++; 
        }
        
        for(auto it:mpp) 
            res.push_back({it.second,it.first}); 

        sort(res.begin(),res.end(),comp); // O(nlogn)

        for (int i=0;i<k;i++) //O(k)
            ans.push_back(res[i].second);

        return ans;
    }
};

// Time complexity: O(nlogn)
// Space complexity: O(2*n+k)
// k is space taken by ans, and n is length taken by map and res
