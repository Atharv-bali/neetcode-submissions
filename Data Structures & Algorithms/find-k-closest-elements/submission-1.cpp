class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int n = arr.size(),cnt=0;
        priority_queue<pair<int,int>, vector<pair<int,int>>> pq;
        vector<int> res;
        for(int i=0;i<n;i++) {
            pq.push({abs(arr[i]-x),i});
            if((int)pq.size()>k)
                pq.pop();
        }
        while(!pq.empty()) {
            int index = pq.top().second;
            res.push_back(arr[index]);
            pq.pop();
        }
        sort(res.begin(),res.end());
        return res;
    }
};
//Time complexity: O(nlogn)
//Space complexity: O(k)