class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {

        priority_queue<pair<double,pair<int,int>>, vector<pair<double,pair<int,int>>>, greater<pair<double,pair<int,int>>>> pq;
        int n = points.size();
        double dist;
        vector<vector<int>> ans;

        for(int i=0;i<n;i++) { //O(nlogn)
            dist = sqrt(points[i][1]*points[i][1]+points[i][0]*points[i][0]);
            pq.push({dist,{points[i][0],points[i][1]}});
        }

        for(int i=0;i<k;i++) { //O(k)
            ans.push_back({pq.top().second.first,pq.top().second.second});
            pq.pop();
        }

        return ans;
    }
};
//Time complexity: O(nlogn)
//Space complexity: O(n)