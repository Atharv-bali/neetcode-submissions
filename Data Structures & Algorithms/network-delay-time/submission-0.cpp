class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int,int>>> adj(n+1);
        for(auto &it:times) {
            int u = it[0];
            int v = it[1];
            int d = it[2];
            adj[u].push_back({d,v});
        }
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        vector<int> vis(n+1,1e9);
        vis[k] = 0;
        pq.push({0,k});

        while(!pq.empty()) {
            int d = pq.top().first;
            int v = pq.top().second;
            pq.pop();
            if(d > vis[v])
                continue;
            for(auto &it:adj[v]) {
                int dist = it.first;
                int node = it.second;
                if(d+dist < vis[node]) {
                    vis[node] = d+dist;
                    pq.push({vis[node],node});
                }
            }
        }
        int ans=0;
        for(int i=1;i<=n;i++) 
            ans = max(ans,vis[i]);
        return ans==1e9?-1:ans;
    }
};
//Time complexity: O(ElogV) = O(times.size()*logn)
//Space complexity: O(n)