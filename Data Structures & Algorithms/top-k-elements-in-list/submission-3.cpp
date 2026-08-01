class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        vector<int> ans;
        int freq = 0;
        sort(nums.begin(),nums.end());
        for(int i=0;i<nums.size();i++) {
            if(i==0 || nums[i]==nums[i-1])
                freq++;
            else {
                pq.push({freq,nums[i-1]}); //O(logn)
                if(pq.size()>k)
                    pq.pop();
                freq=1;
            }
        }
        pq.push({freq,nums[nums.size()-1]});
        if(pq.size()>k)
            pq.pop();
        for(int i=0;i<k;i++) {
            ans.push_back(pq.top().second);
            pq.pop();
        }

        return ans;
    }
};

// Time complexity: O(nlogn)
// Space complexity: O(n+k)
// k is space taken by ans, and n is length taken by map and res
