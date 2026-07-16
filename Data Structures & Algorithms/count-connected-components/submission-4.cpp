class Solution {
public:
    void dfs(int node, int n, vector<vector<int>> &edges, vector<vector<int>> &adj, vector<int> &vis) {
        vis[node] = 1;
        for(auto &it:adj[node]) { //O(E)
            if(!vis[it]) {
                dfs(it,n,edges,adj,vis);
            }
        }
        return;
    }
    int countComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        int cnt=0;
        for(auto &it:edges) { //O(E)
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        vector<int> vis(n,0);
        for(int i=0;i<n;i++) { //O(V)
            if(!vis[i]) {
                cnt++;
                dfs(i,n,edges,adj,vis);
            }
        }
        return cnt;
    }
};
//Time complexity: O(V+E)
//Space complexity: O(V)