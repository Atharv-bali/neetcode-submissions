class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        priority_queue<pair<int,int>, vector<pair<int,int>>> pq;
        unordered_map<int,int> mpp;
        vector<int> ans;
        for(int &num:nums) {
            mpp[num]++; // O(n)
        }
        for(auto it:mpp) // O(nlogn)
            pq.push({it.second,it.first}); //O(logn)
        while(k!=0) {
            ans.push_back(pq.top().second);
            pq.pop(); // O(logn)
            k--;
        }
        return ans;
    }
};

// Time complexity: O(nlogn)
// Space complexity: O(n+k)
// k is space taken by ans, and n is length taken by map
