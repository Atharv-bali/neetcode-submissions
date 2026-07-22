class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size(),sum=0,dist;
        vector<bool> vis(n,false);
        vector<vector<pair<int,int>>> adj(n);
        for(int i=0;i<n;i++) {
            for(int j=i+1;j<n;j++) {
                dist = abs(points[i][0]-points[j][0])+abs(points[i][1]-points[j][1]);
                adj[i].push_back({dist,j});
                adj[j].push_back({dist,i});
            }
        }
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        pq.push({0,0});
        while(!pq.empty()) {
            int dis = pq.top().first;
            int node = pq.top().second;
            pq.pop();
            if(vis[node])
                continue;
            sum += dis;
            vis[node] = true;
            for(auto &it:adj[node]) {
                int d = it.first;
                int adjNode = it.second;
                if(!vis[adjNode])
                    pq.push({d,adjNode});
            }
        }
        return sum;
    }
};
//Time complexity: O(n^2*logn)
//Space complexity: O(n^2)