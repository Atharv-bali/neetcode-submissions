class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        priority_queue<pair<int,int>, vector<pair<int,int>>> pq;
        unordered_map<int,int> mpp;
        vector<int> ans;
        for(int &num:nums) {
            mpp[num]++;
        }
        for(auto it:mpp)
            pq.push({it.second,it.first});
        while(k!=0) {
            ans.push_back(pq.top().second);
            pq.pop();
            k--;
        }
        return ans;
    }
};
