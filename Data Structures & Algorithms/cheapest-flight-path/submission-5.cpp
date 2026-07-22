class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<int> vis(n,0);
        vector<int> res(n,1e8);
        vector<vector<pair<int,int>>> adj(n);
        priority_queue<pair<int,pair<int,int>>, vector<pair<int,pair<int,int>>>, greater<pair<int,pair<int,int>>>> pq;
        for(auto &it:flights) 
            adj[it[0]].push_back({it[1],it[2]});
        pq.push({0,{src,0}});
        vis[src] = 1;
        while(!pq.empty()) {
            int stop = pq.top().first;
            int source = pq.top().second.first;
            int d = pq.top().second.second;
            pq.pop();
            if(stop>k)
                continue;
            for(auto &it:adj[source]) {
                int dis = it.second;
                int node = it.first;
                if(res[node] > (d+dis) && stop <= k) {
                    res[node] = d+dis;
                    pq.push({stop+1,{node,res[node]}});
                } 
            }
        }
        return res[dst]>1e7?-1:res[dst];
    }
};
//Time complexity: O(K*logE)
//Space complexity: O(V+E)