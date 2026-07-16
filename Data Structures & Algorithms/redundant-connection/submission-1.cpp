class Solution {
public:
    bool dfs(int u, int v, unordered_map<int,vector<int>> adj, vector<bool> &vis) {
        vis[u] = true;
        if(u==v)
            return true;
        for(auto &it:adj[u]) {
            if(vis[it])
                continue;
            if(dfs(it,v,adj,vis))
                return true;
        }
        return false;
    }
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        unordered_map<int,vector<int>> adj;
        int n = edges.size();
        for(auto &edge:edges) { //O(n)
            vector<bool> vis(n,false);
            if(adj.find(edge[0])!=adj.end() && adj.find(edge[1])!=adj.end() && dfs(edge[0],edge[1],adj,vis))//O(n)
                return {edge[0],edge[1]};
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }
        return {};
    }
};
//Time complexity: O(n*n)
//Space complexity: O(n*n)